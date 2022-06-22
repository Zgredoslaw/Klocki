//
// Created by asd on 12.06.18.
//

#include <iostream>
#include <SFML/Graphics/RectangleShape.hpp>
#include <SFML/Graphics/Sprite.hpp>
#include <SFML/Window/Event.hpp>
#include "bitwa.h"
#include <cmath>
#include <SFML/Graphics/Texture.hpp>

bitwa::bitwa(int moc_a, int moc_b) //: powiedzmy(moc_a), drugie(moc_b)
{
  moc1=moc_a;
  moc2=moc_b;
  obiekt o1(100,100);
  o=o1;
  b;
  atak1=0;atak2=0;
    rect.setFillColor(sf::Color::Red);
    rect.setSize(sf::Vector2f(15, 30));

    boot.setFillColor(sf::Color::Blue);
    boot.setSize(sf::Vector2f(15, 30));
    wygrana=false;
    koniec=false;
    strzela=false;
    wczytaj_obrazki();
}
void bitwa::wczytaj_obrazki() {
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

void bitwa::draw(sf::RenderWindow &window) {
    o.hamuj();

    int a=(b.zwr_x()-o.zwr_x())*(b.zwr_x()-o.zwr_x());
    int be=(b.zwr_y()-o.zwr_y())*(b.zwr_y()-o.zwr_y());
    int odleglosc=sqrt(a+be);

    o.przesun();

    bot_mobility();
    attack(odleglosc);
    if(strzela)
        strzal(odleglosc);

    sf::CircleShape kolo(atak2, 20);
    kolo.setPosition(b.zwr_x()-atak2,b.zwr_y()-atak2);
    kolo.setFillColor(sf::Color::Red);
    window.draw(kolo);

    sf::CircleShape kolo1(atak1, 20);
    kolo1.setFillColor(sf::Color::Green);
    kolo1.setPosition(o.zwr_x()-atak1,o.zwr_y()-atak1);
    window.draw(kolo1);
    if(moc1==3) {
        ludzik2.setPosition(o.zwr_x() - 16, o.zwr_y() - 16);
        window.draw(ludzik2);
    }
    else {
        ludzik1.setPosition(o.zwr_x() - 16, o.zwr_y() - 16);
        window.draw(ludzik1);
    }
    if(moc2==1) {
        ludzik3.setPosition(b.zwr_x() - 16, b.zwr_y() - 16);
        window.draw(ludzik3);
    }
    else {
        ludzik4.setPosition(b.zwr_x() - 16, b.zwr_y() - 16);
        window.draw(ludzik4);
    }

}
void bitwa::bot_mobility()
{
    if(o.zwr_x()-b.zwr_x()>0) b.przesun(4, moc2);
    if(o.zwr_x()-b.zwr_x()<0) b.przesun(3, moc2);
    if(o.zwr_y()-b.zwr_y()>0) b.przesun(2, moc2);
    if(o.zwr_y()-b.zwr_y()<0) b.przesun(1, moc2);
}


void bitwa::handleEvent(sf::Event &event)
{
    if(event.type == sf::Event::KeyPressed ){
        if(event.key.code == sf::Keyboard::Up ) {
            o.zmiana_pedu(1, 0);
        }
        if(event.key.code == sf::Keyboard::Down) {
            o.zmiana_pedu(2, 0);
        }
        if(event.key.code == sf::Keyboard::Right) {
            o.zmiana_pedu(0, 1);
        }
        if(event.key.code == sf::Keyboard::Left) {
            o.zmiana_pedu(0, 2);
        }
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::B))
        strzela=true;
}

void bitwa::attack(int odleglosc) // zajmuje się atakiem bota
{
    if(odleglosc<moc2*65 && atak2<moc2*20) atak2=atak2+moc2*0.05;
    if(odleglosc>moc2*65 && atak2>1.5) atak2=atak2-moc2*0.05;
    if(odleglosc<atak2 && atak2>moc2*19) koniec=true;
}

void bitwa::strzal(int odleglosc){
    if(atak1<moc1*20) atak1=atak1+moc1*0.05;
    if(atak1>moc1*19){
        if(odleglosc<atak1) {
            koniec = true;
            wygrana = true;
        }
        atak1=0;
        strzela=false;
    }
}
bool bitwa::czy_koniec() {
    return koniec;
}
bool bitwa::czy_wygrana() {
    return wygrana;
}
void bitwa::ustaw(int a, int be){
    moc1=a;
    moc2=be;
    obiekt o1(100,100);
    o=o1;
    bot b1;
    b=b1;
    atak1=0;atak2=0;
    rect.setFillColor(sf::Color::Red);
    rect.setSize(sf::Vector2f(15, 30));
    boot.setFillColor(sf::Color::Blue);
    boot.setSize(sf::Vector2f(15, 30));
    wygrana=false;
    koniec=false;
    strzela=false;
}