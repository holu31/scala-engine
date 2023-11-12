#include <engine/physics/shapes/PhysicsCube.hpp>

PhysicsCube::PhysicsCube(glm::vec3 scale,
    float mass, float restitution,
    glm::vec3 inertia
) {

    btCollisionShape *shape = new btBoxShape(btVector3(scale.x, scale.y, scale.z));
    btMotionState *transform = new btDefaultMotionState(btTransform(
            btQuaternion(0, 0, 0),
            btVector3(0, 1.5, -3)
    ));
    this->mass = mass;
    this->inertia = inertia;
    this->restitution = restitution;

    btRigidBody::btRigidBodyConstructionInfo rbConstrInfo(btScalar(mass), transform, shape);
    rbConstrInfo.m_restitution = restitution;
    
    rb = new btRigidBody(rbConstrInfo);
    rb->forceActivationState(DISABLE_DEACTIVATION);
    
    Physics::dynamicsWorld->addRigidBody(rb);

}