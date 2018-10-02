#include "Ball.h"
#include "Mechanics.h"
#include <math.h>
#include "Paddle.h"
#include <iostream>

using namespace std;

Ball::Ball(Vertex momentum_i) {
    shape.setOrigin(radius, radius);
    position.x = WIDTH / 2;
    position.y = HEIGHT / 2;
    shape.setPosition(position.x, position.y);
    shape.setRadius(radius);
    shape.setFillColor(sf::Color(255, 140, 0));

    momentum = momentum_i;

//    ///////////!!!!!!!!!!!!!
//    momentum.x = 25; ///
//    momentum.y = 25; /// Initial ball speed
//    ///////////!!!!!!

}

void Ball::move(Paddle left_paddle, Paddle right_paddle) {

    ///Rebound from top and bottom walls
    if (position.y + radius >= HEIGHT){
        int y_momentum_sign = -1;
        momentum.y = abs(momentum.y) * y_momentum_sign;}

    if (position.y - radius <= 0)
        momentum.y = abs(momentum.y);


    ///Rebound from paddles
    int sim_x = position.x + radius;
    int sim_y = position.y;


    ///Process right paddle
    if ( sim_x >= right_paddle.position.x) {

        ///Hitting right paddle
        if ((right_paddle.position.y < sim_y) and (sim_y < right_paddle.position.y + right_paddle.height)) {

            int middle_paddle = (right_paddle.position.y + right_paddle.height/2);
            int rel = abs(middle_paddle - sim_y); ///sim_y is y coordinate of the hitting ball
            int sign = (sim_y > middle_paddle)? 1: -1;
            momentum.x *= -1;
            momentum.y = (rel/15 + 5) * sign;

        } else {

            ///Left scores point
            game_point.left_won = true;
            game_point.point_scored = true;
            ///

        }

    }

    ///Process left paddle
    if (position.x  - radius <= left_paddle.position.x + left_paddle.width) {

        ///Hitting left paddle
        if ((left_paddle.position.y < sim_y) and (sim_y < left_paddle.position.y + left_paddle.height)) {

            int middle_paddle = (left_paddle.position.y + left_paddle.height/2);
            int rel = abs(middle_paddle - sim_y);
            int sign = (sim_y > middle_paddle)? 1: -1;
            momentum.x *= -1;
            momentum.y = (rel/15 + 5) * sign;

//            cout<<"momentum y: "<<momentum.y<<endl; ///For checking the speed given by the function above
//            cout<<"momentum x: "<<momentum.x<<endl;

        } else {

            ///Right scores point
            game_point.left_won = false;
            game_point.point_scored = true;
            ///

        }
    }

    ///Move ball
    position.x += momentum.x;
    position.y += momentum.y;

    shape.setPosition(position.x, position.y);

}
