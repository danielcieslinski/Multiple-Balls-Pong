#pragma once
#define WIDTH 1280
#define HEIGHT 720
#define pixels_from_wall 10
#include <SFML/Window.hpp>

struct Vertex{
    int x, y;
};

struct GamePoint{
    bool point_scored, left_won;
};

class CountDownText{

public:
    CountDownText();


};
