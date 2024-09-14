/*------------------------*
 * ECS by Benjamin Bourge *
 *------------------------*/

#include <iostream>
#include <vector>
#include <cstring>
#include <SFML/Graphics.hpp>
#include "../include/core/coordinator.hpp"
#include "../include/core/ecs.hpp"
#include "../include/core/texture.hpp"
#include "../include/core/components/transform.hpp"
#include "../include/core/components/spriteRenderer.hpp"
#include "../include/core/components/tag.hpp"
#include "../include/core/components/camera.hpp"

bool isDebug()
{
    return true;
}

void createCamera(std::shared_ptr<Coordinator> coordinator)
{
    Entity camera = coordinator->createEntity();

    coordinator->addComponent<Transform>(camera, Transform(1920/2, 1080/2, 1, 1));
    coordinator->addComponent<Camera>(camera);
    coordinator->addComponent<Tag>(camera, Tag("camera"));
}

int main()
{
    srand(time(nullptr));
    std::shared_ptr<Coordinator> coordinator = getCoordinator();
    createCamera(coordinator);


    //put here your code to instanciate entities
    Entity e = coordinator->createEntity();
    coordinator->addComponent<Transform>(e, Transform(400, 300, 1, 1));
    coordinator->addComponent<SpriteRenderer>(e, SpriteRenderer(TEXTURE_TYPE_EXAMPLE, 32, 32));


    if (serverRunning())
        return 0;

    int fps = 0;
    float timerFps = 0;
    while (coordinator->_window->isOpen()) {
        sf::Event event;
        while (coordinator->_window->pollEvent(event)) {
            if (event.type == sf::Event::Closed)
                coordinator->_window->close();
        }
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Escape)) {
            coordinator->_window->close();
            break;
        }
        coordinator->_window->clear();
        coordinator->update();
        if (isDebug()) {
            fps++;
            timerFps += coordinator->_deltaTime;
            if (timerFps >= 1) {
                //std::cout << fps << std::endl;
                if (fps < 50)
                    std::cerr << "Low fps, Cause:" << coordinator->_highConsumingSystem << " with " << coordinator->_highConsumingTime << "ms per frame" << std::endl;
                fps = 0;
                timerFps = 0;
                //coordinator->_networkManager->_clock.restart();
                //coordinator->_networkManager->sendPacket(coordinator->_networkManager->makePacket(CMD_PING, {}));
            }
        }
        coordinator->_window->display();
    }

    return 0;
}