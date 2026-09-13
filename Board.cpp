#include <iostream>
#include <iomanip>
#include "Board.h"

using namespace std;

Board::Board() {
    setupBoard();
}
void Board::setupBoard() {
    clearBoard();
    setupPieces();
}
void Board::clearBoard() {
    for(int row=0;row<8;row++){
        for(int collumn=0;collumn<8;collumn++){
            Board[row][collumn]=".";
        }
    }
}
void Board::setupPieces() {
    string backRow[8]={
        "Rook", "Knight", "Bishop", "Queen", "King", "Bishop", "Knight", "Rook"
    };
    for(int collumn=0;collumn<8;collumn++) {
        board[0][collumn]=backRow[collumn];
        board[1][collumn]="Pawn";
        board[6][collumn]="Pawn";
        board[7][collumn]=backRow[collumn];
    }
}
void Board::printBoard() {
    cout<<endl;
    cout<<"          a       b       c       d       e       f       g       h"<<endl;
    cout<<"    ---------------------------------------------------------------"<<endl;
    for(int row=0;row<8;row++) {
        printRow(row);
    }
    cout<<"    ---------------------------------------------------------------"<<endl;
}
void Board::printRow(int row) {
    for(int collumn=0;collumn<8;collumn++) {
        printSquare(row,collumn);
    }
    cout<<endl;
}
void Board::printSquare(int row,int collumn) {
    cout<<setw(8)<<board[row][collumn];
}
bool Board::isInsideBoard(Coordinate position) {
    return position.isValid();
}
string Board::getPiece(Coordinate position) {
    if(isInsideBoard(position)) {
        return board[position.getRow()][position.getCollumn()];
    }
    return "Invalid";
}
void Board::setPiece(Coordinate position, string piece) {
    if(isInsideBoard(position)) {
        board[position.getRow()][position.getCollumn()]=piece;
    }
}
bool Board::movePiece(Coordinate from, Coordinate to) {
    if(!isInsideBoard(from) || !isInsideBoard(to)) {
        return false;
    }
    string piece=getPiece(from);
    if(piece==".") {
        return false;
    }
    setPiece(to, piece);
    setPiece(from. ".");
    return true;
}
