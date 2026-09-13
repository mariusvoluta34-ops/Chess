#ifndef BOARD_H
#define BOARD_H

#include <string>
#include "Coordinate.h"

using namespace std;

enum Player
{
    WHITE_PLAYER,
    BLACK_PLAYER
};

class Board
{
private:
    string board[8][8];
    void clearBoard();
    void setupPieces();
    void printRow(int row);
    void printSquare(int row, int collumn);
    bool isEmpty(int row, int collumn);
    bool isWhitePiece(string piece);
    bool isBlackPiece(string piece);
    bool isOwnPiece(string piece, Player player);
    bool isEnemyPiece(string piece, Player player);
    bool isPathClear(int fromRow, int fromCollumn, int toRow, int toCollumn);
    bool isLegalPawnMove(int fromRow, int fromCollumn, int toRow, int toCollumn, Player player);
    bool isLegalRookMove(int fromRow, int fromCollumn, int toRow, int toCollumn);
    bool isLegalBishopMove(int fromRow, int fromCollumn, int toRow, int toCollumn);
    bool isLegalQueenMove(int fromRow, int fromCollumn, int toRow, int toCollumn);
    bool isLegalKnightMove(int fromRow, int fromCollumn, int toRow, int toCollumn);
    bool isLegalKingMove(int fromRow, int fromCollumn, int toRow, int toCollumn);

public:
    Board();
    void setupBoard();
    void printBoard();
    bool isInsideBoard(Coordinate position);
    bool movePiece(Coordinate from, Coordinate to);
    string getPiece(Coordinate position);
    void setPiece(Coordinate position, string piece);
    bool isLegalMove(Coordinate from, Coordinate to, Player player);
    bool movePiece(Coordinate from, Coordinate to, Player player);
};
#endif