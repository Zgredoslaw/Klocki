//
// Created by qwe on 10.04.18.
//

#ifndef UNTITLED2_SCORE_H
#define UNTITLED2_SCORE_H
#include <SFML/Graphics.hpp>


class Score
{
    sf::Texture texture, texture1;
    sf::Sprite sprite, sprite1;

public:
    Score();
    void draw(sf::RenderWindow & win);
    void draw1(sf::RenderWindow & win);

};


#endif //UNTITLED2_SCORE_H
