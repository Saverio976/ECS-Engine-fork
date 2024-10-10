/*------------------------*
 * ECS by Benjamin Bourge *
 *------------------------*/

#pragma once
#include <unordered_map>
#include <vector>
#include <queue>
#include <memory>
#include "entity.hpp"

class ComponentManager;

class EntityManager {
public:
    EntityManager();
    ~EntityManager();

    Entity createEntity();
    void destroyEntity(Entity entity);
    void setSignature(Entity entity, Signature signature);
    Signature getSignature(Entity entity);

    std::shared_ptr<ComponentManager> _componentManager;
    std::unordered_map<Entity, Signature> getExistingEntities() { return _existingEntities;}
private:
    std::unordered_map<Entity, Signature> _existingEntities;
    std::queue<Entity> _freeEntities;
};
