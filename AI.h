//
// Created by danie_000 on 09.06.2018.
//

#ifndef PONG_AI_H
#define PONG_AI_H

#include "Paddle.h"
#include "Ball.h"
#include <vector>

class AI{

public:
    void make_move(Paddle & paddle, std::vector<Ball> balls);

};


#endif //PONG_AI_H
