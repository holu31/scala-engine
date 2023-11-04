#pragma once

#ifndef VECTOR_H
#define VECTOR_H

#include <glm/glm.hpp>

class Vector3 {

public:

    float x, y, z;

    Vector3(glm::vec3 vec) {
        this->x = vec.x;
        this->y = vec.y;
        this->z = vec.z;
    }

    Vector3(float scalar) {
        this->x = scalar;
        this->y = scalar;
        this->z = scalar;
    };

    Vector3(float x, float y, float z) {
        this->x = x;
        this->y = y;
        this->z = z;
    };

    glm::vec3 to_glm(){
        return glm::vec3(x, y, z);
    }

    friend Vector3 operator+(const Vector3& first, const Vector3& second)
    {
        return Vector3(first.x + second.x,
                        first.y + second.y,
                        first.z + second.z);
    }

    friend Vector3 operator-(const Vector3& first, const Vector3& second)
    {
        return Vector3(first.x - second.x,
                        first.y - second.y,
                        first.z - second.z);
    }

    friend Vector3 operator*(const Vector3& first, const Vector3& second)
    {
        return Vector3(first.x * second.x,
                        first.y * second.y,
                        first.z * second.z);
    }

    friend Vector3 operator/(const Vector3& first, const Vector3& second)
    {
        return Vector3(first.x / second.x,
                        first.y / second.y,
                        first.z / second.z);
    }

};

#endif