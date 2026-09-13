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
            board[row][collumn] = ".";
        }
    }
}
void Board::setupPieces()
    {
        string whiteBackRow[8]= {
            "WRook", "WKnight", "WBishop", "WQueen",
            "WKing", "WBishop", "WKnight", "WRook"
        };

        string blackBackRow[8]= {
            "BRook", "BKnight", "BBishop", "BQueen",
            "BKing", "BBishop", "BKnight", "BRook"
        };

        for (int collumn=0;collumn<8;collumn++)
        {
            board[0][collumn]=blackBackRow[collumn];
            board[1][collumn]="BPawn";
            board[6][collumn]="WPawn";
            board[7][collumn]=whiteBackRow[collumn];
        }
    }

void Board::printBoard()
{
    cout << endl;
    cout << "          a       b       c       d       e       f       g       h" << endl;
    cout << "    ---------------------------------------------------------------" << endl;
    for (int row = 0; row < 8; row++)
    {
        printRow(row);
    }
    cout << "    ---------------------------------------------------------------" << endl;
}
void Board::printRow(int row)
{
    for (int collumn = 0; collumn < 8; collumn++)
    {
        printSquare(row, collumn);
    }
    cout << endl;
}
void Board::printSquare(int row, int collumn)
{
    cout << setw(8) << board[row][collumn];
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
bool Board::isEmpty(int row, int collumn)
{
    return board[row][collumn]==".";
}
bool Board::isWhitePiece(string piece)
{
    return piece.lenght()>0 && piece[0]=='W';
}
bool Board::isBlackPiece(string piece)
{
    return piece.lenght()>0 && piece[0]=='B';
}
bool Board::isOwnPiece(string piece, Player player)
{
    if(piece==".")
    {
        return false;
    }
    if(player==WHITE_PLAYER)
    {
        return isBlackPiece(piece);
    }
    return isWhitePiece(piece);
}
bool Board::isPathClear(int fromRow, int fromCollumn, int toRow, int toCollumn)
{
    int rowStep=0;
    int collumnStep=0;
    if(toRow>fromRow)
    {
        rowStep=1;
    }
    if(toRow<fromRow)
    {
        rowStep=-1;
    }
    if(toCollumn>fromCollumn)
    {
        collumnStep=1;
    }
    if(toCollumn<fromCollumn)
    {
        collumnStep=-1
    }
    int row=fromRow+rowStep;
    int collumn=fromCollumn+collumnStep;
    while (row!=toRow || collumn!=toCollumn)
    {
        if(!isEmpty(row,collumn))
        {
            return false;
        }
        row+=rowStep;
        collumn+=collumnStep;
    }
    return true;
}
bool Board::isLegalPawnMove(int fromRow, int fromCol, int toRow, int toCol, Player player)
{
    int direction;
    int startingRow;
    if (player==WHITE_PLAYER)
    {
        direction=-1;
        startingRow=6;
    }
    else
        {
        direction=1;
        startingRow=1;
        }        
        if (toCollumn==fromCollumn &&
        toRow==fromRow+direction &&
        isEmpty(toRow, toCollumn))
        {
            return true;
        }
        if (toCollumn==fromCollumn &&
            fromRow==startingRow &&
            toRow==fromRow+2*direction &&
            isEmpty(fromRow+direction, fromCollumn) &&
            isEmpty(toRow, toCollumn))
        {
            return true;
        }
        if (abs(toCollumn-fromCollumn)==1 &&
            toRow==fromRow+direction &&
            isEnemyPiece(board[toRow][toCollumn], player))
        {
            return true;
        }

        return false;
    }

    bool Board::isLegalRookMove(int fromRow, int fromCollumn, int toRow, int toCollumn)
    {
        if (fromRow!=toRow && fromCollumn!=toCollumn)
        {
            return false;
        }

        return isPathClear(fromRow, fromCollumn, toRow, toCollumn);
    }

    bool Board::isLegalBishopMove(int fromRow, int fromCollumn, int toRow, int toCollumn)
    {
        if (abs(toRow-fromRow)!=abs(toCollumn-fromCollumn))
        {
            return false;
        }

        return isPathClear(fromRow, fromCollumn, toRow, toCollumn);
    }

    bool Board::isLegalQueenMove(int fromRow, int fromCollumn, int toRow, int toCollumn)
    {
        return isLegalRookMove(fromRow, fromCollumn, toRow, toCollumn) ||
               isLegalBishopMove(fromRow, fromCollumn, toRow, toCollumn);
    }

    bool Board::isLegalKnightMove(int fromRow, int fromCollumn, int toRow, int toCollumn)
    {
        int rowDiff=abs(toRow-fromRow);
        int collumnDiff=abs(toCollumn-fromCollumn);

        return (rowDiff==2 && collumnDiff==1) ||
               (rowDiff==1 && collumnDiff==2);
    }

    bool Board::isLegalKingMove(int fromRow, int fromCollumn, int toRow, int toCollumn)
    {
        int rowDiff=abs(toRow-fromRow);
        int collumnDiff=abs(toCollumn-fromCollumn);

        return rowDiff<=1 && collumnDiff<=1;
    }

    bool Board::isLegalMove(Coordinate from, Coordinate to, Player player)
    {
        if (!isInsideBoard(from) || !isInsideBoard(to))
        {
            return false;
        }

        int fromRow=from.getRow();
        int fromCollumn=from.getCollumn();

        int toRow=to.getRow();
        int toCollumn=to.getCollumn();

        if (fromRow==toRow&&fromCollumn==toCollumn)
        {
            return false;
        }

        string piece=board[fromRow][fromCollumn];
        string destination=board[toRow][toCollumn];

        if (piece==".")
        {
            return false;
        }

        if (!isOwnPiece(piece, player))
        {
            return false;
        }

        if (isOwnPiece(destination, player))
        {
            return false;
        }

        string pieceName=piece.substr(1);

        if (pieceName=="Pawn")
        {
            return isLegalPawnMove(fromRow, fromCollumn, toRow, toCollumn, player);
        }
        else if (pieceName=="Rook")
        {
            return isLegalRookMove(fromRow, fromCollumn, toRow, toCollumn);
        }
        else if (pieceName=="Bishop")
        {
            return isLegalBishopMove(fromRow, fromCollumn, toRow, toCollumn);
        }
        else if (pieceName=="Queen")
        {
            return isLegalQueenMove(fromRow, fromCollumn, toRow, toCollumn);
        }
        else if (pieceName=="Knight")
        {
            return isLegalKnightMove(fromRow, fromCollumn, toRow, toCollumn);
        }
        else if (pieceName=="King")
        {
            return isLegalKingMove(fromRow, fromCollumn, toRow, toCollumn);
        }

        return false;
    }

    bool Board::movePiece(Coordinate from, Coordinate to, Player player)
    {
        if (!isLegalMove(from, to, player))
        {
            return false;
        }

        string piece=getPiece(from);

        setPiece(to, piece);
        setPiece(from, ".");

        return true;
    }

