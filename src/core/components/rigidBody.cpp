/*------------------------*
 * ECS by Benjamin Bourge *
 *------------------------*/

#include "../../../include/core/components/rigidBody.hpp"

RigidBody::RigidBody()
{
    _verletMode = false;
    _speed = {0, 0};
    _acceleration = {0, 0};
    _hasSpawned = false;
    _previousPosition = {0, 0};
}

RigidBody::RigidBody(bool verlet, sf::Vector2f acceleration) : RigidBody()
{
    _verletMode = verlet;
    _acceleration = acceleration;
}

RigidBody::~RigidBody()
{

}
