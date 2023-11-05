#include <engine/Window.hpp>
#include <iostream>
#include <stdio.h>

void frameBufferSizeCallback(GLFWwindow *window, 
    int width, int height)
{
    glViewport(0, 0, width, height);
}

Window::Window(
    int width,
    int height
)
{

    glfwInit();

    glfwDefaultWindowHints();

    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 4);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 6);
    
    glfwWindowHint(GLFW_RESIZABLE, GLFW_FALSE); // Resizable
	glfwWindowHint(GLFW_SAMPLES, 4); // MSAA

    this->m_window = glfwCreateWindow(width, height,
                            "Beta Scala-Engine", nullptr, nullptr);

    if (!m_window) throw fprintf(stderr, "Failed at glfwCreateWindow.\n");

    glfwMakeContextCurrent(this->m_window);
    if(!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress)){
        throw fprintf(stderr, "Glad run failed");
    }

    glEnable(GL_DEPTH_TEST);
    glEnable(GL_CULL_FACE);
    glEnable(GL_TEXTURE_2D);
    glEnable(GL_BLEND);
    glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
    
    glClearColor(0.4f, 0.4f, 0.4f, 0.0f);

    glfwSetFramebufferSizeCallback(this->m_window, frameBufferSizeCallback);

    glfwSwapInterval(0); // VSync

    std::cout << "Vendor: " << glGetString(GL_VENDOR) << std::endl;
    std::cout << "Renderer: " << glGetString(GL_RENDERER) << std::endl;
    std::cout << "Version: " << glGetString(GL_VERSION) << std::endl;
}

Window::~Window()
{
    glfwDestroyWindow(this->m_window);
    glfwTerminate();
}

void Window::runScene(Scene *scene)
{

    double prevDeltaTime = (float) glfwGetTime();

    while (!glfwWindowShouldClose(this->m_window)) {

        glfwPollEvents(); 
        glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

        float deltaTime = (float) glfwGetTime() - prevDeltaTime;
        prevDeltaTime = (float) glfwGetTime();

        scene->draw();

        glfwSwapBuffers(this->m_window);
    }
}