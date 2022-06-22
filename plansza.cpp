//
// Created by asd on 10.06.18.
//

#include "plansza.h"
#include <vector>
#include <iostream>
#include <SFML/Graphics/Texture.hpp>
#include <SFML/Graphics/Sprite.hpp>
#include <SFML/Graphics/RectangleShape.hpp>
#include "postac.h"
#include <cmath>


plansza::plansza(){
    postac p;
    ustaw_pionki(p);
    combat=false;
    laduj_obrazki();
}
void plansza::laduj_obrazki() {
    if (!texture1.loadFromFile("image.png", sf::IntRect(40, 120, 225, 370)))
    {
        std::cout<<"nie udalo sie wczytac grafiki";
    }
    texture2.loadFromFile("image.png", sf::IntRect(315, 120, 225, 370));
    texture3.loadFromFile("image.png", sf::IntRect(40, 515, 225, 370));
    texture4.loadFromFile("image.png", sf::IntRect(315, 515, 225, 370));

    ludzik1.setTexture(texture1);
    ludzik2.setTexture(texture2);
    ludzik3.setTexture(texture3);
    ludzik4.setTexture(texture4);

    ludzik1.scale(sf::Vector2f(0.15f, 0.13f));
    ludzik2.scale(sf::Vector2f(0.15f, 0.13f));
    ludzik3.scale(sf::Vector2f(0.15f, 0.13f));
    ludzik4.scale(sf::Vector2f(0.15f, 0.13f));
}
bool plansza::czy_combat()
{
    return combat;
}
int plansza::czy_koniec() {
    int a=0,b=0;
    for(int i=0; i<postaci.size();i++){
        if(postaci[i].zwr_str()) a++;
        else
            b++;
    }
    if(a==0 )return 1;
    if(b==0) return 2;
    return 0;
}

void plansza::ustaw_pionki(postac p)
{
    for(int i=0; i<9; i++){
        postaci.push_back(p);
        postaci[i].ustaw_pos(0,i);
        postaci[i].ustaw_str(false);
        postaci[i].ustaw_moc(3);
    }
    for(int i=0; i<9; i++){
        postaci.push_back(p);
        postaci[i+9].ustaw_pos(1,i);
        postaci[i+9].ustaw_str(false);
    }
    for(int i=0; i<9; i++){
        postaci.push_back(p);
        postaci[i+18].ustaw_pos(7,i);
        postaci[i+18].ustaw_str(true);
    }
    for(int i=0; i<9; i++){
        postaci.push_back(p);
        postaci[i+27].ustaw_pos(8,i);
        postaci[i+27].ustaw_str(true);
        postaci[i+27].ustaw_moc(3);
    }
}

int plansza::czy_zajete(int x, int y)
{
    for(int i=0; i<36; i++) {
        if(postaci[i].zwr_pos_x()==x && postaci[i].zwr_pos_y()==y ){
            if(postaci[i].zwr_str())
            return i;
            else
                return -2;
        }
    }
    return -1;
}


bool plansza::przesun(int x, int y, int idx)
{
    int moc=postaci[idx].zwr_moc();
    int q=abs(postaci[idx].zwr_pos_x()-x);
    int w=abs(postaci[idx].zwr_pos_y()-y);
    //if(czy_zajete(x,y) && )
    if(q<=moc && w<=moc) {
        postaci[idx].ustaw_pos(x, y);
        return true;
    }
    return false;
}

int plansza::czy_wybrany()
{
    int a=postaci.size();
    for(int i=0; i<a; i++){
        if(postaci[i].czy_wybrany()) return i;
    }
    return -1;
}
void plansza::wybierz(int x, int y) {
    int a=czy_wybrany();
    if(a!=-1) postaci[a].wybierz();
    for(int i=0;i<postaci.size(); i++){
        if(postaci[i].zwr_pos_x()==x && postaci[i].zwr_pos_y()==y && !postaci[i].zwr_str()){
            postaci[i].wybierz();
        }
    }
}


void plansza::rysuj_plansze(sf::RenderWindow &window){

    int odstep=60;
    rect.setSize(sf::Vector2f(50, 50));


    for(int i=0; i<9; i++){
        for(int j=0; j<9; j++){
            rect.setPosition(i*50+odstep, j*50+odstep);
            rect.setFillColor(sf::Color::Green);
            if((i+j)%2==0) rect.setFillColor(sf::Color::Red);
            window.draw(rect);
        }
    }

    if(czy_wybrany()!=-1){
        int a=czy_wybrany();
        rect.setPosition(postaci[a].zwr_pos_x()*50+odstep, postaci[a].zwr_pos_y()*50+odstep);
        rect.setFillColor(sf::Color::Yellow);
        window.draw(rect);
    }



    for(int i=0; i<postaci.size(); i++){
        if(postaci[i].zwr_moc()==1 && !postaci[i].zwr_str()) {
            ludzik1.setPosition(postaci[i].zwr_pos_x() * 50 + odstep + 5, postaci[i].zwr_pos_y() * 50 + odstep);
            window.draw(ludzik1);
        }
        if(postaci[i].zwr_moc()==3 && !postaci[i].zwr_str()) {
            ludzik2.setPosition(postaci[i].zwr_pos_x() * 50 + odstep + 5, postaci[i].zwr_pos_y() * 50 + odstep);
            window.draw(ludzik2);
        }
        if(postaci[i].zwr_moc()==1 && postaci[i].zwr_str()) {
            ludzik3.setPosition(postaci[i].zwr_pos_x() * 50 + odstep + 5, postaci[i].zwr_pos_y() * 50 + odstep);
            window.draw(ludzik3);
        }
        if(postaci[i].zwr_moc()==3 && postaci[i].zwr_str()) {
            ludzik4.setPosition(postaci[i].zwr_pos_x() * 50 + odstep + 5, postaci[i].zwr_pos_y() * 50 + odstep);
            window.draw(ludzik4);
        }
    }
}
int plansza::zwr_moc(int idx) {
    return postaci[idx].zwr_moc();
}
int plansza::ktory_to(int idx) {
    for(int i=0;i<postaci.size(); i++){
        if(postaci[idx].zwr_pos_x()==postaci[i].zwr_pos_x() && postaci[idx].zwr_pos_y()==postaci[i].zwr_pos_y())
            return i;
    }
}
int plansza::ruch_bota(){
    int poczatek=0, koniec=postaci.size()-1, ilosc=0;
    for(int i=0; i<postaci.size(); i++){
        if(postaci[i].zwr_str()){
            if(poczatek==0) poczatek=i;
            ilosc++;
        }
    }
    int idx=rand()%ilosc+poczatek;
    int x=postaci[idx].zwr_pos_x()-postaci[idx].zwr_moc();
    if(postaci[idx].zwr_moc()==3 && x<0)
        x++;
    if(x<0) {
        ruch_bota();
        return -1;
    }
    int y=postaci[idx].zwr_pos_y();

    for(int i=0; i<postaci.size(); i++) {
        if(postaci[i].zwr_pos_x()==x && postaci[i].zwr_pos_y()==y && postaci[i].zwr_str() ){
            ruch_bota();
            return -1;
        }
    }
    postaci[idx].ustaw_pos(x,y);
    for(int i=0; i<postaci.size(); i++) {
        if(postaci[i].zwr_pos_x()==x && postaci[i].zwr_pos_y()==y && !postaci[i].zwr_str() ){
            return i;
        }
    }
    return -1;
}
void plansza::usun(int idx){
    postaci.erase(postaci.begin()+idx);
}

