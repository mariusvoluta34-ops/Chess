#include "Pieces.h"

Piece::Piece(Color c) : color(c) {}
Color Piece::getColor() const
{
    return color;
}

Pawn::Pawn(Color c) : Piece(c) {}
Rook::Rook(Color c) : Piece(c) {}
Knight::Knight(Color c) : Piece(c) {}
Bishop::Bishop(Color c) : Piece(c) {}
Queen::Queen(Color c) : Piece(c) {}
King::King(Color c) : Piece(c) {}