#include "Pieces.h"

Piece::Piece(Color c) : color(c) {}
Color Piece::getColor() const
{
    return color;
}

Pawn::Pawn(Color c) : Piece(c) {}
