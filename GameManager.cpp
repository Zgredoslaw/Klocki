//
// Created by qwe on 10.04.18.
//

#include <iostream>
#include "GameManager.h"
#include "Intro.h"
#include "plansza.h"
#include "Score.h"
#include "bitwa.h"


GameManager::GameManager(Intro & in, Score & sc, plansza & pla, bitwa & bi) : intro(in), score(sc), p(pla), b(bi)
{
    //state = GameManager::GameState::INTRO;
    state = INTRO;
    gra = SZACHOWNICA;
    twoj_ruch=false;
    combat=false;
    wygrana=false;

}

void GameManager::debug_changeCombat() {
    switch (gra)
    {
        case SZACHOWNICA:
            gra = WALKA;
            break;
        case WALKA:
            gra=SZACHOWNICA;
            break;
    }
}

void GameManager::debug_changeState()
{
    switch (state)
    {
        case INTRO:
            state = GAME;
            break;
        case GAME:
            state = SCORE;
            break;
        case SCORE:
            state = INTRO;
            break;
    }
}

void GameManager::PhandleEvent(sf::Event event){

    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Space)){
        debug_changeState();
    }
}
void GameManager::RhandleEvent(sf::Event event){

    if (event.mouseButton.button == sf::Mouse::Left && event.type == sf::Event::MouseButtonPressed )
    {
        int x=event.mouseButton.x%10;
        x=event.mouseButton.x-x;
        x=(x-60)/50;
        int y=event.mouseButton.y%10;
        y=event.mouseButton.y-y;
        y=(y-60)/50;

        int idx=p.czy_wybrany();

        if(idx==-1)
        p.wybierz(x,y);
        else{
            bot_idx=p.czy_zajete(x,y);
            if(bot_idx==-2)
                p.wybierz(x,y);
            else if(bot_idx==-1) {
                if(p.przesun(x, y, idx))
                twoj_ruch=false;
            }
            else {
                twoj_idx=idx;
                b.ustaw(p.zwr_moc(idx), p.zwr_moc(bot_idx));
                p.przesun(x, y, idx);
                twoj_ruch=false;
                combat=true;
            }
        }

        if(p.czy_combat()) {

            debug_changeCombat();
        }
    }
}
void GameManager::ShandleEvent(sf::Event event){
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Space))
        exit(0);
}


void GameManager::handleEvent (sf::Event & event)
{
    switch(state)
    {
        case INTRO:
            PhandleEvent(event);
            break;
        case GAME:
            RhandleEvent(event);
            break;
            case SCORE:
                ShandleEvent(event);
                break;
    }

}

void GameManager::draw(sf::RenderWindow & win)
{
    if(p.czy_combat()) gra=WALKA;
    switch(state)
    {
        case INTRO:
            intro.draw(win);
            break;
        case GAME:
            Draw_Combat(win);
            break;
        case SCORE:
            if(wygrana)
            score.draw(win);
            else
                score.draw1(win);
            break;
    }
}
void GameManager::Draw_Combat(sf::RenderWindow &win) {
    switch(gra)
    {
        case SZACHOWNICA:
            if(!twoj_ruch) {
                int idx=p.ruch_bota();
                if(idx==-1)
                twoj_ruch=true;
                else{
                    twoj_idx=idx;
                    bot_idx=p.ktory_to(idx);
                    b.ustaw(p.zwr_moc(twoj_idx), p.zwr_moc(bot_idx));
                    debug_changeCombat();
                    twoj_ruch=true;
                }
            }
            if(combat) debug_changeCombat();
            p.rysuj_plansze(win);
            break;
        case WALKA:
            if(b.czy_koniec()){
                if(b.czy_wygrana()) p.usun(bot_idx);
                else p.usun(twoj_idx);
                combat=false;
                debug_changeCombat();
                int koniec=p.czy_koniec();
                if(koniec==2) {
                    wygrana=false;
                    debug_changeState();
                }
                if(koniec==1){
                    wygrana=true;
                    debug_changeState();
                }
            }
            b.draw(win);
            break;
    }
}
void GameManager::handleEvent2(sf::Event & event){
    if(gra==WALKA) b.handleEvent(event);
}

