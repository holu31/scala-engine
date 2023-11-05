#pragma once

#include <btBulletDynamicsCommon.h>
#include <btBulletCollisionCommon.h>

class Physics {

    btRigidBody *m_obj;
    bool m_applyForce = false;

public:

    int steps = 7;

    static btDynamicsWorld *dynamicsWorld;

    Physics();
    ~Physics();

};