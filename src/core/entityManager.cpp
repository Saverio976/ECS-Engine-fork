/*------------------------*
 * ECS by Benjamin Bourge *
 *------------------------*/

#include <iostream>
#include "../../include/core/entityManager.hpp"

EntityManager::EntityManager()
{
    for (Entity entity = 0; entity < MAX_ENTITIES; entity++)
        _freeEntities.push(entity);
}

EntityManager::~EntityManager()
{

}

Entity EntityManager::createEntity()
{
    if (_freeEntities.empty()) {
        std::cerr << "ERROR: No more entities available." << std::endl;
        return -1;
    }
    Entity entity = _freeEntities.front();
    _freeEntities.pop();
    _existingEntities[entity] = Signature();
    return entity;
}

void EntityManager::destroyEntity(Entity entity)
{
    _freeEntities.push(entity);
}

void EntityManager::setSignature(Entity entity, Signature signature)
{
    _existingEntities[entity] = signature;
}

Signature EntityManager::getSignature(Entity entity)
{
    return _existingEntities[entity];
}
