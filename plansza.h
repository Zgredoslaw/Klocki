//
// Created by asd on 10.06.18.
//

#ifndef UNTITLED_PLANSZA_H
#define UNTITLED_PLANSZA_H
#include "postac.h"
#include <vector>
#include <SFML/Graphics/RenderWindow.hpp>
#include <SFML/Graphics/Sprite.hpp>
#include <SFML/Graphics/RectangleShape.hpp>
#include <SFML/Graphics/Texture.hpp>


class plansza {
    std::vector <postac> postaci ;
    bool combat;
    sf::Texture texture1, texture2, texture3, texture4;
    sf::Sprite ludzik1, ludzik2, ludzik3, ludzik4;
    sf::RectangleShape rect;

public:
    plansza();
    void ustaw_pionki(postac p);
    void rysuj_plansze(sf::RenderWindow &window);
    bool przesun(int x, int y, int idx);
    int czy_zajete(int x, int y);
    int czy_wybrany();
    void wybierz(int x, int y);
    bool czy_combat();
    int zwr_moc(int idx);
    int ruch_bota();
    int ktory_to(int idx);
    void usun(int idx);
    void laduj_obrazki();
    int czy_koniec();
};


#endif //UNTITLED_PLANSZA_H
