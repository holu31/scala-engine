#pragma once

#include <thirdparty/glad/glad.h>
#define GLFW_INCLUDE_NONE
#include <GLFW/glfw3.h>

#include <glm/glm.hpp>

#include <utils/Vector.hpp>
#include <engine/render/Shaders.hpp>
#include <engine/render/Texture.hpp>
#include <engine/Node.hpp>

#include <iostream>
#include <vector>

class Mesh : public Node {

    void setArrayBuffer(int pos, int size, unsigned int id, std::vector<float> data);
    void setElementArrayBuffer(unsigned int id, std::vector<int> data);

protected:

    GLuint VAO;

    GLuint m_verBuffer;
    GLuint m_indexBuffer;
    GLuint m_norBuffer;
    GLuint m_uvBuffer;

    void updateBuffers();

    Shader *m_shader;
    Texture *m_texture;

    std::vector<float> m_vertices;
    std::vector<int> m_indices;
    std::vector<float> m_normals;
    std::vector<float> m_uv;

public:
        glm::vec3 color = glm::vec3(0.8f);

    Mesh(std::vector<float> vertices,
        std::vector<int> indices, 
        std::vector<float> normals,
        std::vector<float> uv);
    Mesh() {}

    void start() override;
    void draw() override;

    void setTexture(Texture *texture);

};