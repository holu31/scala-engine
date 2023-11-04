#pragma once

#include <thirdparty/glad/glad.h>
#define GLFW_INCLUDE_NONE
#include <GLFW/glfw3.h>

#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>

#include <engine/Node.h>

#include <iostream>

class Camera : public Node {

public:
    static Camera *current;

    float fov = 90.0f;
    float near = 0.01f;
    float far = 100.0f;

    Camera();
    ~Camera();

    glm::mat4 projMatGet();
    glm::mat4 viewMatGet();

};