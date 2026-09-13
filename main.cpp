#include <iostream>
#include "Pieces.h"
using namespace std;

int main()
{
    Pawn pawn(WHITE);
    cout << "Pawn color: " << pawn.getColor() << endl;
    return 0;
}