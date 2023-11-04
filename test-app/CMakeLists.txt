cmake_minimum_required(VERSION 3.10)
project(test-app)

set(CMAKE_CXX_STANDARD 20)
add_compile_options(
    -g
    -Wall
)

include_directories("public/")

add_executable(test-app app.cpp)

# Link libraries
target_link_libraries(test-app ${CMAKE_SOURCE_DIR}/libscala-engine.a glfw)