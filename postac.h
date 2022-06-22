//
// Created by asd on 10.06.18.
//

#ifndef UNTITLED_POSTAC_H
#define UNTITLED_POSTAC_H


class postac {
    int pos_x;
    int pos_y;
    int moc;
    bool exist;
    bool strona; //true prawo, false lewo
    bool wybrany;


public:
    postac();
    int zwr_pos_x();
    int zwr_pos_y();
    int czy_zyje();
    void ustaw_pos(int x, int y);
    void ustaw_str(bool str);
    bool zwr_str();
    void ustaw_moc(int a);
    int zwr_moc();
    bool czy_wybrany();
    void wybierz();


};


#endif //UNTITLED_POSTAC_H
