#include <iostream>
#include <string>
#include <iomanip>
#include "Board.h"

using namespace std;

int main()
{
    Board chessBoard;
    Player currentPlayer=WHITE_PLAYER;
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
    else
    {
        cout<<"Black Ai turn."<<endl;
        cout<<"Ai is broken bruh."<<endl;
        cout<<"Just enter black move manually"<<endl;
        cout<<"Move:";
        cin>>fromLetter>>fromNumber>>toLetter>>toNumber;
        Coordinate from(fromLetter, fromNumber);
        Coordinate to(toLetter, toNumber);
        if(chessBoard.movePiece(from, to, BLACK_PLAYER))
        {
            cout<<"Black move done."<<endl;
            currentPlayer=WHITE_PLAYER;
        }
        else{
            cout<<"Hoooly illegal move"<<endl;
        }
    }
}
cout << "GG goodluck next time" << endl;

return 0;