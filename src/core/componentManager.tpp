/*------------------------*
 * ECS by Benjamin Bourge *
 *------------------------*/

#include <iostream>

template<typename T>
std::shared_ptr<ComponentArray<T>> ComponentManager::getComponentArray()
{
    const char* typeName = typeid(T).name();

    if (_componentsArray.find(typeName) == _componentsArray.end()) {
        std::cerr << "Component not registered" << std::endl;
        return nullptr;
    }
    return std::static_pointer_cast<ComponentArray<T>>(_componentsArray[typeName]);
}

template <typename T>
void ComponentManager::addComponent(Entity entity)
{
    std::shared_ptr<ComponentArray<T>> componentArray = getComponentArray<T>();
    if (componentArray == nullptr) {
        std::cerr << "Component not registered" << std::endl;
        return;
    }
    componentArray->addComponent(entity);
    Signature signature = componentArray->getSignature();
    Signature entitySignature = _entityManager->getSignature(entity);
    _entityManager->setSignature(entity, entitySignature | signature);
}

template <typename T>
void ComponentManager::addComponent(Entity entity, T componentType) {
    std::shared_ptr<ComponentArray<T>> componentArray = getComponentArray<T>();
    if (componentArray == nullptr) {
        std::cerr << "Component not registered" << std::endl;
        return;
    }
    componentArray->addComponent(entity, componentType);
    Signature signature = componentArray->getSignature();
    Signature entitySignature = _entityManager->getSignature(entity);
    _entityManager->setSignature(entity, entitySignature | signature);
}

template <typename T>
void ComponentManager::removeComponent(Entity entity)
{
    std::shared_ptr<ComponentArray<T>> componentArray = getComponentArray<T>();
    if (componentArray == nullptr) {
        std::cerr << "Component not registered" << std::endl;
        return;
    }
    componentArray->removeComponent(entity);
    Signature signature = componentArray->getSignature();
    Signature entitySignature = _entityManager->getSignature(entity);
    _entityManager->setSignature(entity, entitySignature & ~signature);
}

template <typename T>
T& ComponentManager::getComponent(Entity entity)
{
    std::shared_ptr<ComponentArray<T>> componentArray = getComponentArray<T>();
    if (componentArray == nullptr) {
        std::cerr << "Component not registered, returning a temporary component" << std::endl;
        return *std::make_shared<T>();
    }
    return componentArray->getComponent(entity);
}

template <typename T>
void ComponentManager::registerComponent()
{
    const char* typeName = typeid(T).name();

    _componentsArray[typeName] = std::make_shared<ComponentArray<T>>();
    Signature signature;
    signature.set(_nextComponentSignature++, true);
    _componentsArray[typeName]->setSignature(signature);
}

template <typename T>
Signature ComponentManager::getComponentSignature()
{
    const char* typeName = typeid(T).name();

    return _componentsArray[typeName]->getSignature();
}

template <typename T>
std::vector<Entity> ComponentManager::getAllEntitiesWithComponent()
{
    std::vector<Entity> entities;

    return _componentsArray[typeid(T).name()]->getListOfEntities();
}