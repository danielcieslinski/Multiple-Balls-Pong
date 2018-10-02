//
// Created by danie_000 on 09.06.2018.
//

#include "AI.h"
#include "Ball.h"
#include <vector>
#include <iostream>

void AI::make_move(Paddle & paddle, std::vector<Ball> balls) {

    Vertex closest_position = balls[0].position;

    for (int i = 1; i < balls.size() ; ++i)
        closest_position =  (abs(balls[i].position.x -paddle.position.x) < abs(closest_position.x - paddle.position.x))? balls[i].position : closest_position;

    int middle_paddle = (paddle.position.y + paddle.height/2);

    if (closest_position.y < middle_paddle - 50)
        paddle.move_up();
    else if(closest_position.y > middle_paddle + 50)
        paddle.move_down();


}