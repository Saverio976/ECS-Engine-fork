/*------------------------*
 * ECS by Benjamin Bourge *
 *------------------------*/

#include "../../../../include/core/systems/collisionSystem.hpp"
#include "../../../../include/core/coordinator.hpp"
#include "../../../../include/core/ecs.hpp"
#include "../../../../include/core/components/transform.hpp"
#include "../../../../include/core/components/boxCollider.hpp"

CollisionSystem::CollisionSystem()
{
    _signature = getCoordinator()->getComponentSignature<Transform>();
    _signature |= getCoordinator()->getComponentSignature<BoxCollider>();
}

CollisionSystem::~CollisionSystem()
{

}

void CollisionSystem::update(float deltaTime)
{
    std::shared_ptr<Coordinator> coordinator = getCoordinator();

    if (sf::Keyboard::isKeyPressed(sf::Keyboard::P) && isDebug() && !isServer())
        drawDebugBoxes();

    for (auto const &entity : _entityMoved) {
        auto &boxCollider = coordinator->_componentManager->getComponent<BoxCollider>(entity);
        if (boxCollider._mode == COLLISION_MODE_STATIC)
            continue;
        auto &transform = coordinator->_componentManager->getComponent<Transform>(entity);
        boxCollider._entitiesCollided.clear();

        for (auto const &entity2 : _entitiesThisFrame) {
            if (entity == entity2)
                continue;
            if (!coordinator->hasComponent<BoxCollider>(entity2))
                continue;

            auto &boxCollider2 = coordinator->_componentManager->getComponent<BoxCollider>(entity2);
            if ((boxCollider._mask & boxCollider2._layer) == 0)
                continue;
            auto &transform2 = coordinator->_componentManager->getComponent<Transform>(entity2);

            if (!(transform._x + boxCollider._offsetX + boxCollider._width / 2 <= transform2._x + boxCollider2._offsetX - boxCollider2._width / 2 ||
                  transform._x + boxCollider._offsetX - boxCollider._width / 2 >= transform2._x + boxCollider2._offsetX + boxCollider2._width / 2 ||
                  transform._y + boxCollider._offsetY + boxCollider._height / 2 <= transform2._y + boxCollider2._offsetY - boxCollider2._height / 2 ||
                  transform._y + boxCollider._offsetY - boxCollider._height / 2 >= transform2._y + boxCollider2._offsetY + boxCollider2._height / 2)) {
                boxCollider._entitiesCollided.push_back(entity2);
            }
        }
    }
    _entityMoved.clear();
}

void CollisionSystem::drawDebugBoxes()
{
    std::shared_ptr<Coordinator> coordinator = getCoordinator();

    for (auto entity: _entitiesThisFrame) {
        auto &collisionBox = coordinator->_componentManager->getComponent<BoxCollider>(entity);
        auto &transform = coordinator->_componentManager->getComponent<Transform>(entity);

        sf::VertexArray lineStrip(sf::LineStrip, 5);
        Entity camera = coordinator->getEntityFromTag("camera");
        auto &cameraTransform = coordinator->_componentManager->getComponent<Transform>(camera);

        int tx = transform._x + collisionBox._offsetX - cameraTransform._x + 1920 / 2;
        int ty = transform._y + collisionBox._offsetY - cameraTransform._y + 1080 / 2;

        lineStrip[0].position = {tx - collisionBox._width / 2, ty - collisionBox._height / 2};
        lineStrip[1].position = {tx + collisionBox._width / 2, ty - collisionBox._height / 2};
        lineStrip[2].position = {tx + collisionBox._width / 2, ty + collisionBox._height / 2};
        lineStrip[3].position = {tx - collisionBox._width / 2, ty + collisionBox._height / 2};
        lineStrip[4].position = {tx - collisionBox._width / 2, ty - collisionBox._height / 2};
        lineStrip[0].color = sf::Color::Green;
        lineStrip[1].color = sf::Color::Green;
        lineStrip[2].color = sf::Color::Green;
        lineStrip[3].color = sf::Color::Green;
        lineStrip[4].color = sf::Color::Green;
        coordinator->_window->draw(lineStrip);
    }
}

void CollisionSystem::addedEntity(Entity entity)
{
    _entityMoved.push_back(entity);
}

void CollisionSystem::removedEntity(Entity entity)
{

}

void CollisionSystem::entityMoved(Entity entity)
{
    bool found = false;

    for (auto &e : _entityMoved)
        if (e == entity)
            found = true;
    if (!found)
        _entityMoved.push_back(entity);
}

