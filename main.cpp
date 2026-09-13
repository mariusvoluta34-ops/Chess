#include <iostream>
#include <windows.h>
#include "Board.h"

using namespace std;

int main()
{
    SetConsoleOutputCP(CP_UTF8);
    Board chessBoard;
    Player currentPlayer = WHITE_PLAYER;
    char fromLetter;
    int fromNumber;
    char toLetter;
    int toNumber;
    while (true)
    {
        chessBoard.printBoard();
        cout << endl;
        cout << (currentPlayer == WHITE_PLAYER ? "White" : "Black") << " move" << endl;
        cout << "Enter q to quit the game" << endl;
        cout << "Move:";
        cin >> fromLetter;
        if (fromLetter == 'q')
        {
            break;
        }
        cin >> fromNumber >> toLetter >> toNumber;
        Coordinate from(fromLetter, fromNumber);
        Coordinate to(toLetter, toNumber);
        if (chessBoard.movePiece(from, to, currentPlayer))
        {
            cout << "Move complete." << endl;
            currentPlayer = currentPlayer == WHITE_PLAYER ? BLACK_PLAYER : WHITE_PLAYER;
        }
        else
        {
            cout << "Illegal move." << endl;
        }
    }
    cout << "Game over." << endl;
    return 0;
}