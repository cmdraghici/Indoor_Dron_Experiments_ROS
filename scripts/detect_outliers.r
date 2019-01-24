my_data <- read.delim("~/ros_ws/keyframes/KeyFramesDuration.txt")
cuartil.primero <- quantile(my_data$Durations)[2]
mediana <- quantile(my_data$Durations)[3]
cuartil.tercero <- quantile(my_data$Durations)[4]
iqr <- cuartil.tercero - cuartil.primero

extremo.superior.outlaier.normal = cuartil.tercero + 1.5 * iqr
extremo.superior.outlaier.extremo = cuartil.tercero + 4 * iqr

vector.es.outlier.normal <- (my_data$Durations > extremo.superior.outlaier.normal)
vector.es.outlier.extremo <- (my_data$Durations > extremo.superior.outlaier.extremo)

length(vector.es.outlier.normal[vector.es.outlier.normal == TRUE])
length(vector.es.outlier.extremo[vector.es.outlier.extremo == TRUE])