#include <engine/Window.h>
#include <engine/Camera.h>
#include <engine/render/Cube.h>
#include <engine/render/Texture.h>
#include <engine/Scene.h>
#include <utils/Vector.h>
#include <iostream>

class TestScene : public Scene {
public:
    TestScene() {
        
        Camera *camera = new Camera();

        Texture *texture = new Texture("test.png");
        Cube *cube = new Cube();

        cube->setTexture(texture);

        camera->pos = glm::vec3(0.0f, 0.0f, 1.5f);

        this->addChild(camera);
        this->addChild(cube);
    }

    ~TestScene(){}
};

int main()
{
    Window window(1280, 720);

    TestScene *test_scene = new TestScene();
    window.runScene(test_scene);
}