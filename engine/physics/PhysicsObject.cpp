#include <engine/physics/PhysicsObject.hpp>

#include <iostream>


PhysicsObject::PhysicsObject(
    btCollisionShape *shape, btMotionState *transform, float mass,
        glm::vec3 inertia, float restitution)
{

    this->mass = mass;
    this->inertia = inertia;
    this->restitution = restitution;

    btRigidBody::btRigidBodyConstructionInfo rbConstrInfo(btScalar(mass), transform, shape);
    rbConstrInfo.m_restitution = restitution;
    
    rb = new btRigidBody(rbConstrInfo);
    rb->forceActivationState(DISABLE_DEACTIVATION);
    
    Physics::dynamicsWorld->addRigidBody(rb);

}

PhysicsObject::~PhysicsObject() {}

void PhysicsObject::setOrigin(float x, float y, float z) {
    btTransform transform = rb->getWorldTransform();
    transform.setIdentity();

    transform.setOrigin(btVector3(x, y, z));

    rb->setWorldTransform(transform);
}

glm::vec3 PhysicsObject::getOrigin() {
    btVector3 origin = rb->getWorldTransform().getOrigin();

    return glm::vec3(origin.getX(), origin.getY(), origin.getZ());
}

glm::vec3 PhysicsObject::getBasis() {
    btMatrix3x3 basis = rb->getWorldTransform().getBasis();

    btScalar yaw, pitch, roll;

    basis.getEulerZYX(yaw, pitch, roll);

    return glm::vec3(roll, pitch, yaw);
}

void PhysicsObject::draw() {
    Node::draw();
    
    pos = getOrigin();
}