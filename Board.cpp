#include <iostream>
#include <iomanip>
#include "Board.h"

using namespace std;

Board::Board()
{
    setupBoard();
}
void Board::setupBoard()
{
    clearBoard();
    setupPieces();
}
void Board::clearBoard()
{
    for (int row = 0; row < 8; row++)
    {
        for (int collumn = 0; collumn < 8; collumn++)
        {
            board[row][collumn] = " ";
        }
    }
}
void Board::setupPieces()
{
    string backRow[8] = {
        "Rook", "Knight", "Bishop", "Queen", "King", "Bishop", "Knight", "Rook"};
    for (int collumn = 0; collumn < 8; collumn++)
    {
        board[0][collumn] = backRow[collumn];
        board[1][collumn] = "Pawn";
        board[6][collumn] = "Pawn";
        board[7][collumn] = backRow[collumn];
    }
}

void Board::printBoard()
{
    cout << "  ┌────────┬────────┬────────┬────────┬────────┬────────┬────────┬────────┐\n";

    for (int row = 0; row < 8; row++)
    {
        printRow(row);

        if (row < 7)
        {
            cout << "  ├────────┼────────┼────────┼────────┼────────┼────────┼────────┼────────┤\n";
        }
    }

    cout << "  └────────┴────────┴────────┴────────┴────────┴────────┴────────┴────────┘\n";
}

void Board::printRow(int row)
{
    cout << "  │";

    for (int column = 0; column < 8; column++)
    {
        printSquare(row, column);
    }

    cout << "\n";
}

void Board::printSquare(int row, int column)
{
    cout << setw(8) << board[row][column] << "│";
}
bool Board::isInsideBoard(Coordinate position)
{
    return position.getRow() >= 0 && position.getRow() < 8 &&
           position.getCollumn() >= 0 && position.getCollumn() < 8;
}
string Board::getPiece(Coordinate position)
{
    if (isInsideBoard(position))
    {
        return board[position.getRow()][position.getCollumn()];
    }
    return "Invalid";
}
void Board::setPiece(Coordinate position, string piece)
{
    if (isInsideBoard(position))
    {
        board[position.getRow()][position.getCollumn()] = piece;
    }
}
bool Board::movePiece(Coordinate from, Coordinate to)
{
    if (!isInsideBoard(from) || !isInsideBoard(to))
    {
        return false;
    }
    string piece = getPiece(from);
    if (piece == ".")
    {
        return false;
    }
    setPiece(to, piece);
    setPiece(from, ".");
    return true;
}
