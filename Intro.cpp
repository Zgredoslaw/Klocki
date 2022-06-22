//
// Created by qwe on 10.04.18.
//

#include "Intro.h"
#include <SFML/Graphics.hpp>
#include <iostream>
#include "plansza.h"
#include "GameManager.h"


Intro::Intro()
{
    if (!texture.loadFromFile("intro.png"))
    {
        std::cout<<"nie udalo sie wczytac grafiki";
    }
    sprite.setTexture(texture);

}


void Intro::draw(sf::RenderWindow & win)
{
    win.draw(sprite);
}



