/*------------------------*
 * ECS by Benjamin Bourge *
 *------------------------*/

#pragma once
#include <vector>
#include <memory>
#include <queue>
#include <map>
#include <unordered_map>
#include "entity.hpp"
#include "entityManager.hpp"

class IComponentArray {
public:
    virtual ~IComponentArray() = default;
    virtual void entityDestroyed(Entity entity) = 0;
    virtual std::vector<Entity> getListOfEntities() = 0;
    virtual Signature getSignature() = 0;
    virtual void setSignature(Signature signature) = 0;
};

template<typename T>
class ComponentArray : public IComponentArray {
public:
    ComponentArray();
    ~ComponentArray();

    void addComponent(Entity entity);
    void addComponent(Entity entity, T component);
    void removeComponent(Entity entity);
    T& getComponent(Entity entity);
    void entityDestroyed(Entity entity) override;
    virtual std::vector<Entity> getListOfEntities() override;
    Signature getSignature() override { return _signature; }
    void setSignature(Signature signature) override { _signature = signature; }

    std::unordered_map<Entity, std::shared_ptr<T>> _components;
    Signature _signature;
};

#include "../../src/core/componentArray.tpp"

class ComponentManager {
public:
    ComponentManager();
    ~ComponentManager();

    void init();
    template<typename T> void registerComponent();

    template<typename T> void addComponent(Entity entity);
    template<typename T> void addComponent(Entity entity, T component);
    template<typename T> void removeComponent(Entity entity);
    template<typename T> T& getComponent(Entity entity);
    template<typename T> std::shared_ptr<ComponentArray<T>> getComponentArray();
    template<typename T> Signature getComponentSignature();
    template<typename T> std::vector<Entity> getAllEntitiesWithComponent();

    void entityDestroyed(Entity entity);

    std::shared_ptr<EntityManager> _entityManager;

    int _nextComponentSignature = 0;
private:
    std::unordered_map<const char*, std::shared_ptr<IComponentArray>> _componentsArray;
};

#include "../../src/core/componentManager.tpp"
