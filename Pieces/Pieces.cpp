#include "Pieces.h"

PieceColor::PieceColor(Color c) : color(c) {}
Color PieceColor::getColor() const
{
    return color;
}
Pawn::Pawn(Color c) : Piece(c) {}
