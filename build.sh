#!/bin/bash

ENGINE_BUILD_DIR="build"

INCLUDE_DIR="public"
SHADERS_DIR="shaders"

APP="test-app"
APP_BUILD_DIR="build"

cmake -S . -B $ENGINE_BUILD_DIR
cd $ENGINE_BUILD_DIR
make
cp libscala-engine.a ../$APP/libscala-engine.a
cd ..
rm -rd $APP/$INCLUDE_DIR
cp -r $INCLUDE_DIR $APP/$INCLUDE_DIR
cd $APP
rm -rd build/$SHADERS_DIR
cmake -S . -B build
cp -r ../$SHADERS_DIR ../$APP/build/$SHADERS_DIR
cd $APP_BUILD_DIR
make
if [ "$1" == "run" ]; then
./$APP
fi
cd ..
cd ..