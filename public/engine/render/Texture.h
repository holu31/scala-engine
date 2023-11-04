#pragma once

#include <thirdparty/glad/glad.h>
#define GLFW_INCLUDE_NONE
#include <GLFW/glfw3.h>

#include <glm/glm.hpp>

#include <iostream>

class Texture {
    
    glm::ivec2 size;
    int channels;
    unsigned char *data;

    unsigned int id;

public:

    Texture(std::string texturePath);
        

    void import();

    void bind();

    void unbind();

};