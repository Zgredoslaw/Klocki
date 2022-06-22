//
// Created by qwe on 10.04.18.
//

#ifndef UNTITLED2_GAMEMANAGER_H
#define UNTITLED2_GAMEMANAGER_H

#include "GameManager.h"
#include "Intro.h"
#include "plansza.h"
#include "Score.h"
#include "bitwa.h"

class GameManager
{
    Intro & intro;
    Score & score;
    plansza & p;
    bitwa & b;

    enum GameState { INTRO, GAME, SCORE} state;
    enum StanGry {SZACHOWNICA, WALKA} gra;

    bool twoj_ruch, combat, wygrana;
    int twoj_idx, bot_idx;



public:
    GameManager(Intro & in, Score & sc, plansza & pla, bitwa & bi);
    void draw(sf::RenderWindow & win);
    void Draw_Combat(sf::RenderWindow & win);
    void handleEvent (sf::Event & event);
    void debug_changeState();
    void debug_changeCombat();
    void PhandleEvent(sf::Event event);
    void RhandleEvent(sf::Event event);
    void ShandleEvent(sf::Event event);
    void handleEvent2(sf::Event & event);
};


#endif //UNTITLED2_GAMEMANAGER_H
