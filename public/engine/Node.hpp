#pragma once

#include <vector>

#include <glm/ext.hpp>

class Node {

    Node *m_parent = nullptr;
    std::vector<Node*> m_children {};

    glm::vec3 globalPos() const;
    glm::vec3 globalRot() const;

public:

    bool visible = false;

    glm::vec3 pos { 0.0f };
    glm::vec3 rot { 0.0f };
    glm::vec3 scale { 1.0f };

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

    virtual void start();
    virtual void draw();
};