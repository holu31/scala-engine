#include <engine/Window.hpp>
#include <engine/Camera.hpp>
#include <engine/render/Cube.hpp>
#include <engine/render/Texture.hpp>
#include <engine/Scene.hpp>

#include <iostream>

class TestScene : public Scene {
public:
    TestScene() {
        
        Camera *camera = new Camera();

        Texture *texture = new Texture("../assets/test.png");
        Cube *cube = new Cube();

        Cube *cube2 = new Cube();
        camera->pos = glm::vec3(0.0f, 0.0f, 1.5f);

        cube->rot.y = 45.0f;

        cube->setTexture(texture);

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