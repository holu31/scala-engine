#pragma once

#include <btBulletDynamicsCommon.h>
#include <btBulletCollisionCommon.h>

#include <glm/glm.hpp>

#include <engine/physics/Physics.hpp>
#include <engine/Node.hpp>


class PhysicsObject : public Node {

protected:

    PhysicsObject() {}

public:

    float mass;
    glm::vec3 inertia;
    float restitution;

    btRigidBody* rb;

    PhysicsObject(btCollisionShape *shape, btMotionState *transform, float mass,
        glm::vec3 inertia, float restitution = 0.25f);
    ~PhysicsObject();

    void setOrigin(float x, float y, float z);
    glm::vec3 getOrigin();

    void setBasis(float x, float y, float z);
    glm::vec3 getBasis();

    void draw() override;

};