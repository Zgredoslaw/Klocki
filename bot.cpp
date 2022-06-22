//
// Created by asd on 18.06.18.
//

#include "bot.h"
bot::bot(){
    x=200;
    y=100;
    z=0.05;
}
void bot::przesun(int kier, int moc){
    if(moc==3) z=1;
    if(moc==1) z=0.5;
    if(kier==1 && y>0)   y=y-z;
    if(kier==2 && y<780) y=y+z;
    if(kier==3 && x>0)   x=x-z;
    if(kier==4 && y<780) x=x+z;
}
int bot::zwr_x() {
    return x;
}
int bot::zwr_y() {
    return y;
}