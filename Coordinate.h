#ifndef COORDINATE_H
#define COORDINATE_H

class Coordinate {
    private: char letter;
             int number;
             public:
             Coordinate(char l, int n);
             char getLetter();
             int getNumber();
             int getRow();
             int getCollumn();
};
#endif