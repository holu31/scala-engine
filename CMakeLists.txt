cmake_minimum_required(VERSION 3.10)
project(scala-engine)

set(CMAKE_CXX_STANDARD 20)
add_compile_options(
    -g
    -Wall
)


include_directories("public/")
include_directories("public/thirdparty/")

# Add source files
set(SOURCE_LIB
    engine/Window.cpp
    engine/Camera.cpp
    engine/Node.cpp
    engine/physics/Physics.cpp
    engine/physics/PhysicsObject.cpp
    engine/physics/shapes/PhysicsCube.cpp
    engine/render/Shaders.cpp
    engine/render/Mesh.cpp
    engine/render/Cube.cpp
    engine/render/Texture.cpp
    thirdparty/glad/glad.c
)

# Build executable
add_library(scala-engine STATIC ${SOURCE_LIB})

# Link libraries
target_link_libraries(scala-engine glfw dl pthread BulletCollision LinearMath BulletDynamics)