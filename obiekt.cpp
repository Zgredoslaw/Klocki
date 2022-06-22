//
// Created by asd on 17.06.18.
//

#include <iostream>
#include "obiekt.h"
obiekt::obiekt(){

}
obiekt::obiekt(int pos_x, int pos_y) : y(pos_y), x(pos_x)
{
    //x=pos_x; y=pos_y;
    //x=50; y=50;
    ped_g=0; ped_d=0;
    ped_p=0; ped_l=0;
    z=0.05;

}
void obiekt::info(){
    std::cout<<ped_g<<ped_d<<ped_l<<ped_p<<std::endl;
}
void obiekt::zmiana_pedu(int g_d, int p_l) {
    if(g_d==1 ) {
        if(ped_g<2) ped_g=ped_g+2*z;
        if(ped_d>0) ped_d=ped_d-2*z;
    }
    if(g_d==2 ) {
        if(ped_d<2) ped_d=ped_d+2*z;
        if(ped_g>0) ped_g=ped_g-2*z;
    }
    if(p_l==1) {
        if(ped_p<2) ped_p=ped_p+2*z;
        if(ped_l>0) ped_l=ped_l-2*z;
    }
    if(p_l==2) {
        if(ped_l<2) ped_l=ped_l+2*z;
        if(ped_p>0) ped_p=ped_p-2*z;
    }
}
void obiekt::hamuj() {
    if(ped_p>0) ped_p=ped_p-z;
    if(ped_l>0) ped_l=ped_l-z;
    if(ped_g>0) ped_g=ped_g-z;
    if(ped_d>0) ped_d=ped_d-z;

}
void obiekt::przesun() {
    if(x<780)
        x = x + ped_p;
    if(x>0)
        x = x - ped_l;
    if(y<780)
        y = y + ped_d;
    if(y>0)
        y = y - ped_g;
}
int obiekt::zwr_x() {
    return x;
}
int obiekt::zwr_y() {
    return y;
}