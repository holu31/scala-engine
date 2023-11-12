#pragma once

#include <engine/physics/PhysicsObject.hpp>

class PhysicsCube : public PhysicsObject {

public:

    PhysicsCube(glm::vec3 scale = glm::vec3(1.0f),
        float mass = 1.0f, float restitution = .25f,
        glm::vec3 inertia = glm::vec3(1.0f));

};