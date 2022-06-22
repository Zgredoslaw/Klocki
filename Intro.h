//
// Created by qwe on 10.04.18.
//

#ifndef UNTITLED2_INTRO_H
#define UNTITLED2_INTRO_H
#include <SFML/Graphics.hpp>

class Intro
{
    sf::Texture texture;
    sf::Sprite sprite;
public:
    Intro();
    void draw(sf::RenderWindow & win);
};



#endif //UNTITLED2_INTRO_H
