#include <engine/Window.hpp>
#include <engine/Camera.hpp>
#include <engine/render/Cube.hpp>
#include <engine/render/Texture.hpp>
#include <engine/Node.hpp>
#include <engine/physics/shapes/PhysicsCube.hpp>

#include <iostream>

class TestScene : public Node {
public:
    TestScene() {
        
        Camera *camera = new Camera();

        Texture *texture = new Texture("../assets/test.png");
        Cube *cube = new Cube();

        PhysicsObject *phys_cube = new PhysicsCube();

        phys_cube->addChild(cube);

        camera->pos = glm::vec3(0.0f, 0.0f, 1.5f);

        cube->rot.y = 0.0f;

        cube->setTexture(texture);


        Cube *plane = new Cube();
        plane->scale = glm::vec3(10.0f, 0.5f, 10.0f);

        PhysicsObject *phys_plane = new PhysicsCube(plane->scale, 0.0f);
        phys_plane->setOrigin(0, -4, -1.5);

        phys_plane->addChild(plane);

        this->addChild(camera);
        this->addChild(phys_cube);
        this->addChild(phys_plane);
    }

    ~TestScene(){}
};

int main()
{
    Window window(1280, 720);

    TestScene *test_scene = new TestScene();
    window.runScene(test_scene);
}