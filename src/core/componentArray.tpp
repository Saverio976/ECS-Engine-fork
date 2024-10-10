/*------------------------*
 * ECS by Benjamin Bourge *
 *------------------------*/

#include <iostream>

template<typename T>
ComponentArray<T>::ComponentArray()
{
    _signature = 0;
}

template<typename T>
ComponentArray<T>::~ComponentArray()
{

}

template<typename T>
void ComponentArray<T>::addComponent(Entity entity)
{
    if (entity == NULL_ENTITY) {
        std::cerr << "Cannot add a component to a null entity" << std::endl;
        return;
    }
    if (_components.find(entity) != _components.end()) {
        std::cerr << "Component already exists" << std::endl;
        return;
    }
    _components[entity] = std::make_shared<T>();
}

template<typename T>
void ComponentArray<T>::addComponent(Entity entity, T component)
{
    if (entity == NULL_ENTITY) {
        std::cerr << "Cannot add a component to a null entity" << std::endl;
        return;
    }
    if (_components.find(entity) != _components.end()) {
        std::cerr << "Component already exists" << std::endl;
        return;
    }
    _components[entity] = std::make_shared<T>(component);
}

template<typename T>
void ComponentArray<T>::removeComponent(Entity entity)
{
    if (entity == NULL_ENTITY) {
        std::cerr << "Cannot remove a component of a null entity" << std::endl;
        return;
    }
    if (_components.find(entity) == _components.end()) {
        std::cerr << "Component not found" << std::endl;
        return;
    }
    _components.erase(entity);
}

template<typename T>
T& ComponentArray<T>::getComponent(Entity entity)
{
    if (entity == NULL_ENTITY) {
        std::cerr << "Cannot get a component of a null entity" << std::endl;
        return *std::make_shared<T>();
    }
    if (_components.find(entity) == _components.end()) {
        std::cerr << "Component not found, returning a temporary component" << std::endl;
        return *std::make_shared<T>();
    }
    return *_components[entity];
}

template<typename T>
void ComponentArray<T>::entityDestroyed(Entity entity)
{
    if (entity == NULL_ENTITY) {
        std::cerr << "Cannot destroy a null entity" << std::endl;
        return;
    }
    if (_components.find(entity) == _components.end())
        return;
    _components.erase(entity);
}

template<typename T>
std::vector<Entity> ComponentArray<T>::getListOfEntities()
{
    std::vector<Entity> entities;
    for (auto const& [entity, component] : _components) {
        entities.push_back(entity);
    }
    return entities;
}