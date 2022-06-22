//
// Created by asd on 10.06.18.
//

#include "postac.h"
postac::postac(){
    moc=1;
    wybrany=false;
}
void postac::ustaw_pos(int x, int y){
    pos_x=x;
    pos_y=y;
}
void postac::ustaw_str(bool str) {
    strona=str;
}
bool postac::zwr_str() {
    return strona;
}
int postac::zwr_pos_x() {
    return pos_x;
}
int postac::zwr_pos_y() {
    return pos_y;
}
void postac::ustaw_moc(int a){
    moc=a;
}
int postac::zwr_moc(){
    return moc;
}
bool postac::czy_wybrany() {
    return wybrany;
}
void postac::wybierz(){
    wybrany=!wybrany;
}