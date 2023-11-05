#pragma once

#include <thirdparty/glad/glad.h>
#define GLFW_INCLUDE_NONE
#include <GLFW/glfw3.h>

#include <vector>
#include <engine/Scene.hpp>

class Window {

    GLFWwindow *m_window;

public:

    Window(int width, int height);
    ~Window();

    void runScene(Scene *scene);

};