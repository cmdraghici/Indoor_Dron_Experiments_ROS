#!/bin/sh

if [ -n "$DESTDIR" ] ; then
    case $DESTDIR in
        /*) # ok
            ;;
        *)
            /bin/echo "DESTDIR argument must be absolute... "
            /bin/echo "otherwise python's distutils will bork things."
            exit 1
    esac
    DESTDIR_ARG="--root=$DESTDIR"
fi

echo_and_run() { echo "+ $@" ; "$@" ; }

echo_and_run cd "/home/cezar/bebop_ws/src/topic_tools"

# ensure that Python install destination exists
echo_and_run mkdir -p "$DESTDIR/home/cezar/bebop_ws/install/lib/python2.7/dist-packages"

# Note that PYTHONPATH is pulled from the environment to support installing
# into one location when some dependencies were installed in another
# location, #123.
echo_and_run /usr/bin/env \
    PYTHONPATH="/home/cezar/bebop_ws/install/lib/python2.7/dist-packages:/home/cezar/bebop_ws/build/topic_tools/lib/python2.7/dist-packages:$PYTHONPATH" \
    CATKIN_BINARY_DIR="/home/cezar/bebop_ws/build/topic_tools" \
    "/usr/bin/python" \
    "/home/cezar/bebop_ws/src/topic_tools/setup.py" \
    build --build-base "/home/cezar/bebop_ws/build/topic_tools" \
    install \
    $DESTDIR_ARG \
    --install-layout=deb --prefix="/home/cezar/bebop_ws/install" --install-scripts="/home/cezar/bebop_ws/install/bin"
