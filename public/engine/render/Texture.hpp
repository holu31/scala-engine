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

    uint32_t minFilter = GL_LINEAR;
    uint32_t magFilter = GL_LINEAR;

    uint32_t wrapS = GL_CLAMP;
    uint32_t wrapT = GL_CLAMP;

    Texture(std::string texturePath);
        

    void import();

    void bind();

    void unbind();

};