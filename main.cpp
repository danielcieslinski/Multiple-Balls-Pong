#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <iostream>
#include <time.h>
#include <windows.h>

#include "Paddle.h"
#include "Ball.h"
#include "Mechanics.h"
#include "interfejs.h"
#include "AI.h"
#include <string>
#include <math.h>

using namespace std;

int random(int min_x, int max_x){
    return rand() %( max_x - min_x) + min_x;
}

vector <Ball> gen_balls(int how_many){

    vector <Ball> balls;
    for (int i = 0; i < how_many; ++i) {
        //int sign = (random(0, 2) == 0)? 1 : -1;
        int sign = (i % 2 == 0)? 1 : -1;
        balls.push_back( Ball(Vertex{sign * random(20, 25), sign * random(10, 15) }) ); /// I propose to reduce the speed for multiple
    }
    return balls;

}

GamePoint move_balls(vector <Ball> & balls, Paddle left_paddle, Paddle right_paddle){

    for (auto & ball : balls){
        ball.move(left_paddle, right_paddle);
        if (ball.game_point.point_scored)
            return ball.game_point;
    }
    return GamePoint{false, false};

}

void draw(sf::RenderWindow & window, Paddle left_paddle, Paddle right_paddle, vector <Ball> balls){
    window.draw(left_paddle.shape);
    window.draw(right_paddle.shape);

    for(auto & ball : balls)
        window.draw(ball.shape);

    window.display();
}

void make_countdown_text(sf::RenderWindow &window, float sec){

    sf::Text text;
    sf::Font font;
    font.loadFromFile("arial_black.ttf");
    text.setFont(font);
    string a = to_string( (int) floor(sec) );
    text.setString(to_string( 3 - ((int) floor(sec) )));
    text.setCharacterSize(300);
    text.setFillColor(sf::Color::Black);
    sf::FloatRect textRect = text.getLocalBounds();
    text.setOrigin(textRect.left + textRect.width/2.0f,
                   textRect.top  + textRect.height/2.0f);

    text.setPosition(sf::Vector2f(WIDTH/2.0f, HEIGHT/2.0f));
    window.draw(text);
}

int play_point(sf::RenderWindow &window, int how_many_balls, bool computer, Score &score) {

    Paddle left_paddle(true), right_paddle(false);

    vector <Ball> balls = gen_balls(how_many_balls);

    sf::Clock timer;

    AI ai;



    while (window.isOpen()) {

        sf::Event event;

        ///Handling user game input
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::W))
            left_paddle.move_up();
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::S))
            left_paddle.move_down();

        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up))
            right_paddle.move_up();
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down))
            right_paddle.move_down();
        ///End of handling user game input


        ///Handling other inputs
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed)
                window.close();
            if (event.type == sf::Event::KeyReleased and event.key.code == sf::Keyboard::BackSpace)
                return -1; ///We dont want to read anything

        }
        ///End of handling


        ///Check if point scored
        float sec = timer.getElapsedTime().asSeconds();
        if ( sec > 3) {
            GamePoint eof_point = move_balls(balls, left_paddle, right_paddle);
            if(computer)
                ai.make_move(left_paddle, balls);
            if (eof_point.point_scored) {
                if (eof_point.left_won) return 1;
                else return 2;
            }
            window.clear(sf::Color(220,220,220));
            score.draw(window);
            draw(window, left_paddle, right_paddle, balls);
        } else {
            window.clear(sf::Color(220,220,220));
            score.draw(window);
            make_countdown_text(window, sec);
            draw(window, left_paddle, right_paddle, balls);
        }

    }
    return -1;

}

void start_game(sf::RenderWindow &window, int how_many_balls, bool computer){

    Score score;

    while (score.left_score < 10 and score.right_score <10 and window.isOpen()){
        int res = play_point(window, how_many_balls, computer, score);
        if(res == 2) score.right_score+=1;
        else if (res == 1) score.left_score +=1;
        else if (res == -1) return;

        //TODO Save score, display score
        cout<<"Score: left-"<<score.left_score<<" right-"<<score.right_score<<endl;
    }

//    cout<<"Game finished"<<endl;
    int Who = (score.left_score == 10)? 1:0;

    FinishedGame End(1280, 720, Who);
    End.draw(window);


}

int main()
{
    HWND hwnd = GetConsoleWindow();
    ShowWindow(hwnd, 0);

    sf::RenderWindow window{ sf::VideoMode(WIDTH, HEIGHT), "PING PONG", sf::Style::Close};
    window.setFramerateLimit(60);

    srand( time( NULL ) ); ///Pseudo random numbers, not good solution, but acceptable for generating balls, because randomness is not so important. Better to use instead <random> lib

    Menu menu(window.getSize().x, window.getSize().y);

    while (window.isOpen()) {
        sf::Event event;

        while (window.pollEvent(event)) {
            switch (event.type) {
                case sf::Event::KeyReleased:
                    switch (event.key.code) {
                        case sf::Keyboard::Up:
                            menu.MoveUp();
                            break;

                        case sf::Keyboard::Down:
                            menu.MoveDown();
                            break;

                        case sf::Keyboard::Return:
                            switch (menu.GetPressedItem()) {
                                case 0:
                                    start_game(window, 2, false); ///Set number of balls as second argument
                                    break;
                                case 1:
                                    start_game(window, 2, true ); ///Set number of balls as second argument
                                    break;
                                case 2:
                                    //ShowResults();
                                    break;
                                case 3:
                                    window.close();
                                    break;
                            }
                    }

                    break;
                case sf::Event::Closed:
                    window.close();

                    break;

            }
        }
        window.clear(sf::Color::Black);
        menu.draw(window);
        window.display();
    }
    return 0;
}

//TODO Zapis do pliku po każdym punkcie, Wyswitlenie info kiedy ktos wygra, tzn bedzie mial 10 pkt, struktura FinishedGame w intefejs

