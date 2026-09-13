#include "Coordinate.h"

Coordinate::Coordinate(char l, int n)
{
    letter = l;
    number = n;
}
char Coordinate::getLetter()
{
    return letter;
}
int Coordinate::getNumber()
{
    return number;
}
int Coordinate::getCollumn()
{
    return letter - 'a';
}
int Coordinate::getRow()
{
    return 8 - number;
}
