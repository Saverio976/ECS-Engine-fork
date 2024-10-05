/*------------------------*
 * ECS by Benjamin Bourge *
 *------------------------*/

#include "../../../../include/core/systems/physicsSystem.hpp"
#include "../../../../include/core/coordinator.hpp"
#include "../../../../include/core/ecs.hpp"
#include "../../../../include/core/components/transform.hpp"
#include "../../../../include/core/components/rigidBody.hpp"

PhysicsSystem::PhysicsSystem()
{
    _signature = getCoordinator()->getComponentSignature<Transform>();
    _signature |= getCoordinator()->getComponentSignature<RigidBody>();
}

PhysicsSystem::~PhysicsSystem()
{

}

void PhysicsSystem::update(float deltaTime)
{
    std::shared_ptr<Coordinator> coordinator = getCoordinator();

    for (auto entity : _entitiesThisFrame) {
        auto& rigidBody = coordinator->_componentManager->getComponent<RigidBody>(entity);
        auto& transform = coordinator->_componentManager->getComponent<Transform>(entity);

        sf::Vector2f oldPos = {transform._x, transform._y};

        if (!rigidBody._verletMode) {
            //Euler integration
            rigidBody._speed.x += rigidBody._acceleration.x * deltaTime;
            rigidBody._speed.y += rigidBody._acceleration.y * deltaTime;

            transform._x += rigidBody._speed.x * deltaTime;
            transform._y += rigidBody._speed.y * deltaTime;
        } else {
            //Verlet integration
            if (!rigidBody._hasSpawned) {
                rigidBody._previousPosition = {transform._x, transform._y};
                rigidBody._hasSpawned = true;
                continue;
            }

            transform._x += (transform._x - rigidBody._previousPosition.x) + rigidBody._acceleration.x * deltaTime * deltaTime;
            transform._y += (transform._y - rigidBody._previousPosition.y) + rigidBody._acceleration.y * deltaTime * deltaTime;
        }

        rigidBody._previousPosition = oldPos;
    }
}

void PhysicsSystem::addedEntity(Entity entity)
{

}

void PhysicsSystem::removedEntity(Entity entity)
{

}
