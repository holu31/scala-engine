#pragma once

#include <thirdparty/glad/glad.h>
#define GLFW_INCLUDE_NONE
#include <GLFW/glfw3.h>

#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>

#include <engine/Node.hpp>

#include <iostream>

class Camera : public Node {

public:
    static Camera *current;

    float fov = 90.0f;
    float near = 0.01f;
    float far = 100.0f;

    Camera();
    ~Camera();

    void makeCurrent();

    glm::mat4 projMat() const;

};