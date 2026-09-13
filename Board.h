#ifndef BOARD_H
#define BOARD_H

#include <string>
#include "Coordinate.h"

using namespace std;

class Board {
    private: string board[8][8];
             void clearBoard();
             void setupPieces();
             void printRow(int row);
             void printSquare(int row, int collumn);
    public:  Board();
             void setupBoard();
             void printBoard();
             bool isInsideBoard(Coordinate position);
             bool movePiece(Coordinate from,Coordinate to);
             string getPiece(Coordinate position);
             void setPiece(Coordinate position, string piece);
};
#endif