#include "Coordinate.h"

Coordinate::Coordinate(char l, int n){
    letter=l;
    number=n;
}
char Coordinate::getLetter() {
    return letter;
}
int Coordinate::getNumber() {
    return number;
}
int Coordinate::getCollumn() {
    return letter-'a';
}
int Coordinate::getRow() {
    return 8-number;
}

bool Coordinate::isValid() {
    return letter>='a' && letter <= 'h' && number>=1 && number <=8
}