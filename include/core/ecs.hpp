/*------------------------*
 * ECS by Benjamin Bourge *
 *------------------------*/

#pragma once
#include <iostream>
#include <SFML/Graphics.hpp>
#include <SFML/Network.hpp>

bool isServer();
bool isDebug();

int serverRunning();

enum Direction
{
    UP,
    DOWN,
    LEFT,
    RIGHT
};

sf::Vector2f getDirection(Direction direction);
sf::Vector2f getPositionOfTile(int x, int y);