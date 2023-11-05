#pragma once

#include <thirdparty/glad/glad.h>
#define GLFW_INCLUDE_NONE
#include <GLFW/glfw3.h>

#include <vector>
#include <engine/Scene.hpp>
#include <engine/physics/Physics.hpp>

class Window {

    GLFWwindow *m_window;
    Physics *m_physics;

public:

    Window(int width, int height);
    ~Window();

    void runScene(Scene *scene);

};