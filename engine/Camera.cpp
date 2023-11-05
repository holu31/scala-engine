#include <engine/Camera.hpp>

Camera::Camera() {
    if (current == nullptr)
        current = this;
}

Camera::~Camera() {
    if (current != nullptr)
        current = nullptr;
}

void Camera::makeCurrent() {
    current = this;
}

glm::mat4 Camera::projMat() const {
    glm::mat4 projMat = glm::mat4(1.0f);
    projMat = glm::perspective(glm::radians(fov), 960.0f / 540.0f, near, far);

    return projMat;
}

Camera* Camera::current = nullptr;