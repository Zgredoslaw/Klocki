//
// Created by asd on 17.06.18.
//

#ifndef UNTITLED_OBIEKT_H
#define UNTITLED_OBIEKT_H


class obiekt {
    double x, y;
    double ped_l, ped_p, ped_d,ped_g;
    double z;

public:
    void info();
    obiekt();
    obiekt(int pos_x, int pos_y);
    void przesun();
    void zmiana_pedu(int g_d, int p_l);
    int  zwr_x();
    int  zwr_y();
    void hamuj();
};


#endif //UNTITLED_OBIEKT_H
