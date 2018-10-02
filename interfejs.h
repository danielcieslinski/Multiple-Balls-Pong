#pragma once
#include "SFML/Graphics.hpp"

#define MAX_NUMBER_OF_ITEMS 4

class Menu
{
public:
    Menu(float width, float height);
    //~Menu();

    void draw(sf::RenderWindow &window);
    void MoveUp();
    void MoveDown();
    int GetPressedItem() { return selectedItemIndex; }

private:
    int selectedItemIndex;
    sf::Font font;
    sf::Text menu[MAX_NUMBER_OF_ITEMS];

};

class FinishedGame{
public:
    FinishedGame(float width, float height, int Who);
    void draw(sf::RenderWindow &window);

private:
    sf::Text text;
    sf::Font font;

};

class Score{
public:
    Score();
    int left_score = 0, right_score = 0;
    void draw(sf::RenderWindow &window);
    sf::Text text1,text2;
    sf::Font font;

};



