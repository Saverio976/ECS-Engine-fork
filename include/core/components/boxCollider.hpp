/*------------------------*
 * ECS by Benjamin Bourge *
 *------------------------*/

#pragma once
#include <vector>
#include <memory>
#include <queue>
#include <map>
#include "../texture.hpp"
#include "../entity.hpp"

#define LAYER_COLLISION_PLAYER 0b1
#define LAYER_COLLISION_ENEMY 0b10

enum CollisionMode {
    COLLISION_MODE_STATIC, //static box won't have any collision inside their _entitiesCollided vector.
    COLLISION_MODE_DYNAMIC
};

class BoxCollider {
public:
    BoxCollider();
    BoxCollider(float width, float height);
    BoxCollider(float width, float height, CollisionMode mode);
    BoxCollider(float width, float height, float offsetX, float offsetY);
    BoxCollider(float width, float height, float offsetX, float offsetY, int mask);
    ~BoxCollider();

    CollisionMode _mode;
    std::bitset<8> _layer;
    std::bitset<8> _mask;

    float _width;
    float _height;
    float _offsetX;
    float _offsetY;
    std::vector<Entity> _entitiesCollided;
};