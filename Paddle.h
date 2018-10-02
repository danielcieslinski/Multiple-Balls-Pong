#pragma once
#include <SFML/Graphics.hpp>
#include "Mechanics.h"




class Paddle {
public:
    Vertex position;

    Paddle(bool left);

    sf::RectangleShape shape;
    const int width = WIDTH / 100;
    const int height = HEIGHT / 4;
    const int max_down = HEIGHT - height;
    const int move_pixels = 20;

    void move_up();
    void move_down();
    void draw();

};

