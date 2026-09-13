#include <iostream>
#include <string>
#include <iomanip>
#include <windows.h>
#include "Board.h"

using namespace std;

int main()
{
    SetConsoleOutputCP(CP_UTF8);
    Board chessBoard;
    char fromLetter;
    int fromNumber;
    char toLetter;
    int toNumber;
    while (true)
    {
        chessBoard.printBoard();
        cout << endl;
        cout << "Enter your move" << endl; // e 2 e 4//
        cout << "Enter q to quit the game loser" << endl;
        cout << "Move:";
        cin >> fromLetter;
        if (fromLetter == 'q')
        {
            break;
        }
        cin >> fromNumber >> toLetter >> toNumber;
        Coordinate from(fromLetter, fromNumber);
        Coordinate to(toLetter, toNumber);
        if (chessBoard.movePiece(from, to))
        {
            cout << "Brilliant move." << endl;
        }
        else
        {
            cout << "You are retarted iqlet." << endl;
        }
    }
    cout << "GG goodluck next time" << endl;
}