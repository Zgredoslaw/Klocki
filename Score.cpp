//
// Created by qwe on 10.04.18.
//

#include "Score.h"
#include <SFML/Graphics.hpp>
#include <iostream>

Score::Score()
{
    if (!texture.loadFromFile("score_win.png"))
    {
        std::cout<<"nie udalo sie wczytac grafiki";
    }
    sprite.setTexture(texture);
    if (!texture1.loadFromFile("score_lose.png"))
    {
        std::cout<<"nie udalo sie wczytac grafiki";
    }
    sprite1.setTexture(texture1);
}

void Score::draw(sf::RenderWindow & win)
{
    win.draw(sprite);

}

void Score::draw1(sf::RenderWindow & win){
    win.draw(sprite1);
}
