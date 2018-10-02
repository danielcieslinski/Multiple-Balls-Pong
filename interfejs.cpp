#include "interfejs.h"
#include "Mechanics.h"
#include <iostream>
#include <SFML/Graphics.hpp>

using namespace std;

Menu::Menu(float width, float height)
{
    if (!font.loadFromFile("Minou DEMO.otf"))
    {
        cout<< "Couldn't find font"<<endl;
    }

    menu[0].setFont(font);
    menu[0].setCharacterSize(50);
    menu[0].setFillColor(sf::Color(255,140,0));
    menu[0].setString("New Game player vs player");
    sf::FloatRect textRect = menu[0].getLocalBounds();
    menu[0].setOrigin(textRect.left + textRect.width/2.0f,
                      textRect.top  + textRect.height/2.0f);
    menu[0].setPosition(sf::Vector2f(width/2.0f, height / (MAX_NUMBER_OF_ITEMS + 1) * 1));


    menu[1].setFont(font);
    menu[1].setCharacterSize(50);
    menu[1].setFillColor(sf::Color::White);
    menu[1].setString("New Game player vs computer");
    sf::FloatRect textRect2 = menu[1].getLocalBounds();
    menu[1].setOrigin(textRect2.left + textRect2.width/2.0f,
                   textRect2.top  + textRect2.height/2.0f);
    menu[1].setPosition(sf::Vector2f(width/2.0f, height / (MAX_NUMBER_OF_ITEMS + 1) * 2 ) );



    menu[2].setFont(font);
    menu[2].setCharacterSize(50);
    menu[2].setFillColor(sf::Color::White);
    menu[2].setString("Continue Game");
    sf::FloatRect textRect3 = menu[2].getLocalBounds();
    menu[2].setOrigin(textRect3.left + textRect3.width/2.0f,
                      textRect3.top  + textRect3.height/2.0f);
    menu[2].setPosition(sf::Vector2f(width/2.0f, height / (MAX_NUMBER_OF_ITEMS + 1) * 3));


	menu[3].setFont(font);
	menu[3].setCharacterSize(50);
	menu[3].setFillColor(sf::Color::White);
	menu[3].setString("Exit");
	sf::FloatRect textRect4 = menu[3].getLocalBounds();
	menu[3].setOrigin(textRect4.left + textRect4.width / 2.0f,
		textRect4.top + textRect4.height / 2.0f);
	menu[3].setPosition(sf::Vector2f(width / 2.0f, height / (MAX_NUMBER_OF_ITEMS + 1) * 4));



    selectedItemIndex = 0;
}


void Menu::draw(sf::RenderWindow &window)
{
    for (int i = 0; i < MAX_NUMBER_OF_ITEMS; i++)
    {
        window.draw(menu[i]);
    }
}

void Menu::MoveUp()
{
    if (selectedItemIndex - 1 >= 0)
    {
        menu[selectedItemIndex].setFillColor(sf::Color::White);
        selectedItemIndex--;
        menu[selectedItemIndex].setFillColor(sf::Color(255,140,0));
    }
}

void Menu::MoveDown()
{
    if (selectedItemIndex + 1 < MAX_NUMBER_OF_ITEMS)
    {
        menu[selectedItemIndex].setFillColor(sf::Color::White);
        selectedItemIndex++;
        menu[selectedItemIndex].setFillColor(sf::Color(255,140,0));
    }
}

FinishedGame::FinishedGame(float width, float height, int Who) {

//    cout<<"Constructed"<<endl;

    if (!font.loadFromFile("Minou DEMO.otf"))
    {
        cout<< "Couldn't find font"<<endl;
    }

    text.setFont(font);
    text.setCharacterSize(80);
    text.setFillColor(sf::Color(255,140,0));

    if (Who == 1)
        text.setString("Player Left Won");
    else if(Who == 0)
        text.setString("Player Right Won");

    sf::FloatRect textRect = text.getLocalBounds();
    text.setOrigin(textRect.left + textRect.width/2.0f,
                      textRect.top  + textRect.height/2.0f);

    text.setPosition(sf::Vector2f(width/2.0f, height / 2.0f));

}

void FinishedGame::draw(sf::RenderWindow &window) {

    window.clear();
    window.draw(text);
    window.display();
    sf::Event event;
    while (window.isOpen())
        while (window.pollEvent(event)) {
            switch (event.type) {
                case sf::Event::KeyReleased:
                    return;
            }
        }

}

Score::Score() {
    left_score = 0; right_score = 0;
    if (!font.loadFromFile("arial_black.ttf"))
    {
        cout << "Couldn't find font" << endl;
    }

    text1.setFont(font);
    text1.setCharacterSize(100);
    text1.setFillColor(sf::Color::Black);
    text1.setString("2");

    sf::FloatRect text1Rect = text1.getLocalBounds();
    text1.setOrigin(text1Rect.left + text1Rect.width / 2.0f,
                    text1Rect.top + text1Rect.height / 2.0f);

    text1.setPosition(sf::Vector2f(WIDTH/ 4.0f, 40));

    text2.setFont(font);
    text2.setCharacterSize(100);
    text2.setFillColor(sf::Color::Black);
    text2.setString("1");

    sf::FloatRect text2Rect = text2.getLocalBounds();
    text2.setOrigin(text2Rect.left + text2Rect.width / 2.0f,
                    text2Rect.top + text2Rect.height / 2.0f);

    text2.setPosition(sf::Vector2f(WIDTH / 4.0f * 3.0f, 40));

}
void Score::draw(sf::RenderWindow &window) {

    text1.setString(to_string(left_score));
    text2.setString(to_string(right_score));
    window.draw(text1);
    window.draw(text2);

}