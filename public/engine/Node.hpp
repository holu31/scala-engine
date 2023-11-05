#pragma once

#include <vector>

#include <glm/ext.hpp>

class Node {

    Node *m_parent = nullptr;
    std::vector<Node*> m_children {};

public:

    bool visible = false;

    glm::vec3 pos = glm::vec3(0.0f);
    glm::vec3 rot = glm::vec3(0.0f);
    glm::vec3 scale = glm::vec3(1.0f);

    Node();
    virtual ~Node();

    Node *parent() const;
    void reparent(Node*);

    std::vector<Node*> children() const;
    bool hasChild(Node*) const;

    void addChild(Node*);

    void removeChild(Node*);

    glm::mat4 transMat() const;
    glm::mat4 viewMat() const;

    glm::vec3 globalPos() const;
    glm::vec3 globalRot() const;

    virtual void draw();
};