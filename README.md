# Algoritmos de estimación de movimiento propio para drones

En este proyecto se integra el paquete bebop_autonomy junto con el paquete ORB-SLAM2 en la plataforma ROS, para poder realizar la localización y el mapeado simultaneo en el dron Parrot Beobop 2. Se desea realizar una serie de experimentos sobre este sistema para poder obtimizar sus parametros de arranque de cara a su uso en interiores.

## Integración del Sistema

A continuación se explicará como realizar la instalación paso a paso y los requisitos para integrar dicho sistema.

### Prerequisitos

Es necesario tener instalada la plataforma ROS, en el PC en el que se va a integrar el sistema.

Se recomienda instalar la versión de ROS Kinect.

El sistema operativo más actualizado y con el que mejor funcina la versión ROS Kinect es el Ubuntu 16.04.

### bebop_autonomy

El paquete bebop_autonomy será el paquete encargado de la comunicación entre el dron y la plataforma ROS.

#### Firmware Dron

Para el correcto funcionamiento de este paquete se requiere previamente instalar en el dron la versión del firmware disponible en "./bebop_versions/4.0.3". La instalación del firmware se podrá realizar siguiendo las indicación mostradas a continuación:

1. Descargar la versión del firmware a instalar. Archivo con extensión .plf
2. Renombrar el archivo a “bebopdrone_usb_update.plf”.
3. Introducir la información en un pendrive con formato de fichero FAT32.
4. Conectar al dron apagado.
5. Encender el dron.
6. Esperar por alrededor de 10 minutos.
7. Remover la batería.
8. Remover USB.
9. Conectar batería y encender el dron.

#### Instalación

El paquete bebop_autonomy posee una serie de prerequisitos que se pueden instalar de forma sencilla con el siguiente comando:

```
$ sudo apt-get install build-essential python-rosdep python-catkin-tools
```

Para instalar el paquete de forma limpia se puede realizar a traves de las instrucciones de los desarrolladores presentes en la web: https://bebop-autonomy.readthedocs.io/en/latest/installation.html

### ORB-SLAM2

ORB_SLAM2 es el paquete encargado de realizar la localización y el mapeo simultaneo.

Antes de poder realizar la construcción del paquete es necesaria la instalación de las siguientes dependencias:

#### Eigen3

Consideraciones:

Se recomienda que la primera dependencia a instalar sea Eigen3, debido a que está dependencia a su vez no tiene otras dependencias, además, Pangolin también depende de Eigen3. La versión utilizada es la 3.1.0, ya que, los desarrolladores de ORB-SLAM2 la recomiendan.

Otro de los hallazgos con respecto a esta librería es que la instalación la efectúa en la ubicación “/usr/local/include/eigen3/Eigen”, pero al realizar breves ejemplos para comprobar el correcto funcionamiento de esta librería, el compilador, esperaba la librería en “/usr/local/include/Eigen”. Se ha observado que ORB-SLAM2 supone que la libreria está instalada en “/usr/local/include/eigen3/Eigen”. Por otro lado Pangolin no especifica donde espera la instalación por lo que para evitar posibles errores se ha copiado esta librería también en la ubicación “/usr/local/include/Eigen”.

#### OpenCV

Consideraciones:

Se ha instalado la librería OpenCV 3.2 por recomendación de los desarrolladores de ORB-SLAM2. Realmente en este punto no importa si se instala primero Pangolin o OpenCV. Para la instalación de OpenCV la web oficial no ofrece demasiada información, por lo que se ha seguido el tutorial de Adrian Rosebrock.

#### Pangolin

Consideraciones:

Dependencias de Pangolin:
* C++11
* OpenGL se recomienda comprobar la correcta instalación de esta librería mediante la ejecución de un código de ejemplo
* Glew se recomienda comprobar la correcta instalación de esta librería mediante la ejecución de un código de ejemplo
* CMake
* Python2/Python3 en este caso se ha utilizado Python2.7
* En cuanto a las librerías opcionales se ha instalado: FFMPEG, DC1394, libuvc, libjpeg, libpng, libtiff, libopenexr, OpenNI / OpenNI2.
* En cuanto a las librerías muy opcionales, solo se ha instalado Eigen3

#### Instalación

El paquete ORB-SLAM2 se ha obtenido del repositorio: "https://github.com/raulmur/ORB_SLAM2". Sin embargo, se recomienda la utilización del paquete presente en la carpeta "./ORB_SLAM2" ya que, posee ciertas modificaciones en el código, necesarias para llevar a cabo los experimentos y la comunicación entre paquetes. Para poder llevar a cabo la instalación de ORB-SLAM2 se recomiendan las siguientes instrucciones:

```
cd ORB_SLAM2
chmod +x build.sh
./build.sh
export ROS_PACKAGE_PATH=${ROS_PACKAGE_PATH}:PATH/ORB_SLAM2/Examples/ROS
chmod +x build_ros.sh
./build_ros.sh
```

### Ejecución

Para poder ejecutar todo el sistema se deben seguir los siguientes pasos:

1. Conectarse al dron a través de la red wifi.
2. Iniciar el core de ros con el comando:
```
$ roscore
```
3. En una nueva terminal cargar el “setup.bash” del proyecto en el que se encuentra bebop_autonomy:
```
$ source bebop_ws/devel/setup.bash
```
4. Ejecutar el paquete bebop_autonomy con el comando:
```
$ roslaunch bebop_tools bebop_nodelet_iv.launch
```
5. En una nueva terminal cargar el “setup.bash” del proyecto ros con el comando:
```
$ cd ORB_SLAM2
$ source ./Examples/ROS/ORB_SLAM2/build/devel/setup.bash
```
6. Ejecutar el paquete ORB-SLAM2 con el comando:
```
$ cd ORB_SLAM2
$ rosrun ORB_SLAM2 Mono Vocabulary/ORBvoc.txt Examples/Monocular/bebop2_camera_calibration.yaml
```

Nota: el objeto Vocabulary/ORBvoc.txt debe descomprimirse en primera instancia.
