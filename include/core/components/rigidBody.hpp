/*------------------------*
 * ECS by Benjamin Bourge *
 *------------------------*/

#pragma once
#include <vector>
#include <memory>
#include <queue>
#include <map>
#include <SFML/Graphics.hpp>
#include "../entity.hpp"

class RigidBody {
public:
    RigidBody();
    RigidBody(bool verlet, sf::Vector2f acceleration);
    ~RigidBody();

    sf::Vector2f _speed;
    sf::Vector2f _acceleration;

    /* for verlet*/
    bool _hasSpawned;
    bool _verletMode;
    sf::Vector2f _previousPosition;
};