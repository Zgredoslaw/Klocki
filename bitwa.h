//
// Created by asd on 12.06.18.
//

#ifndef UNTITLED_BITWA_H
#define UNTITLED_BITWA_H


#include <SFML/Graphics/RenderWindow.hpp>
#include <SFML/Graphics/CircleShape.hpp>
#include <SFML/Graphics/Sprite.hpp>
#include <SFML/Graphics/Texture.hpp>
#include "obiekt.h"
#include "bot.h"

class bitwa {
    obiekt o;
    bot b;
    int moc1,moc2;
    double atak1, atak2;
    sf::RectangleShape rect, boot;
    bool koniec, wygrana, strzela;
    sf::Texture texture1, texture2, texture3, texture4;
    sf::Sprite ludzik1, ludzik2, ludzik3, ludzik4;

public:
    bitwa(int moc_a,int moc_b);
    void draw(sf::RenderWindow &window);
    void handleEvent(sf::Event & event);
    void bot_mobility();
    void attack(int odleglosc);
    bool czy_koniec();
    bool czy_wygrana();
    void strzal(int odleglosc);
    void ustaw(int a, int b);
    void wczytaj_obrazki();
};


#endif //UNTITLED_BITWA_H
