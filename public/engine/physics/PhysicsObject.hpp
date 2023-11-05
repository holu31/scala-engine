#pragma once

#include <btBulletDynamicsCommon.h>
#include <btBulletCollisionCommon.h>

#include <glm/glm.hpp>

#include <engine/physics/Physics.hpp>
#include <engine/Node.hpp>


class PhysicsObject : public Node {

    btCollisionShape* m_shape;
    btMotionState* m_transform;

public:

    float mass;
    glm::vec3 inertia;
    float restitution;
    
    btRigidBody* rb;

    PhysicsObject(btCollisionShape *shape, btMotionState *transform, float mass,
        glm::vec3 inertia, float restitution = 0.25f);
    ~PhysicsObject();

    void draw() override;

};