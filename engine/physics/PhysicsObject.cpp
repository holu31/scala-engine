#include <engine/physics/PhysicsObject.hpp>

#include <iostream>


PhysicsObject::PhysicsObject(
    btCollisionShape *shape, btMotionState *transform, float mass,
        glm::vec3 inertia, float restitution)
{

    this->m_shape = shape;
    this->m_transform = transform;
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

void PhysicsObject::draw() {
    Node::draw();

    btTransform transform = rb->getWorldTransform();

    btVector3 rbPosition = transform.getOrigin();
    btMatrix3x3 rbRotation = transform.getBasis();
    
    rbPosition = btVector3(parent()->globalPos().x + rbPosition.getX(), parent()->globalPos().y + rbPosition.getY(), parent()->globalPos().z + rbPosition.getZ());
    pos = glm::vec3(rbPosition.getX(), rbPosition.getY(), rbPosition.getZ());

    transform.setOrigin(rbPosition);

    btScalar yaw, pitch, roll;

    rbRotation.getEulerZYX(yaw, pitch, roll);

    rbRotation = btMatrix3x3(btQuaternion(parent()->globalRot().z + roll,
                            parent()->globalRot().y + pitch,
                            parent()->globalRot().x + yaw));
    rot = glm::vec3(parent()->globalRot().x + yaw, parent()->globalRot().y + pitch, parent()->globalRot().z + roll);

    transform.setBasis(rbRotation);

    m_transform->setWorldTransform(transform);
}