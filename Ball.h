#pragma once
#include <SFML/Graphics.hpp>
#include "Mechanics.h"
#include "Paddle.h"

class Ball 
{
public:
	Ball(Vertex momentum);
    sf::CircleShape shape;
    void move(Paddle left_paddle, Paddle right_paddle);

    GamePoint game_point{false, false};
    Vertex position;
	
private:
	Vertex momentum;

	const int radius = 22;
	const int speed = 10;

};

