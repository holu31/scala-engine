#include <engine/Window.hpp>
#include <engine/Camera.hpp>
#include <engine/render/Cube.hpp>
#include <engine/render/Texture.hpp>
#include <engine/Scene.hpp>
#include <engine/physics/PhysicsObject.hpp>

#include <iostream>

class TestScene : public Scene {
public:
    TestScene() {
        
        Camera *camera = new Camera();

        Texture *texture = new Texture("../assets/test.png");
        Cube *cube = new Cube();

        btCollisionShape *boxShape = new btBoxShape(btVector3(cube->scale.x, cube->scale.y, cube->scale.z));
        btDefaultMotionState *motionState = new btDefaultMotionState(btTransform(
            btQuaternion(0, 0, 0, 1),
            btVector3(0, 1.5, -3)
        ));

        PhysicsObject *phys_cube = new PhysicsObject(boxShape, motionState, 1.0f,
            glm::vec3(1.0f), .25f);

        phys_cube->addChild(cube);

        camera->pos = glm::vec3(0.0f, 0.0f, 1.5f);

        cube->rot.y = 0.0f;

        cube->setTexture(texture);


        Cube *plane = new Cube();
        plane->scale = glm::vec3(10.0f, 0.5f, 10.0f);

        btCollisionShape *planeShape = new btBoxShape(btVector3(plane->scale.x, plane->scale.y, plane->scale.z));
        btDefaultMotionState *motionState2 = new btDefaultMotionState(btTransform(
            btQuaternion(0, 0, 0, 1),
            btVector3(0, -4, -3)
        ));

        PhysicsObject *phys_plane = new PhysicsObject(planeShape, motionState2, 0.0f,
            glm::vec3(1.0f), .25f);

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