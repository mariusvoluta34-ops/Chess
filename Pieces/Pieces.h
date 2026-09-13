#ifndef PIECES_H
#define PIECES_H

enum Color
{
    WHITE,
    BLACK
};
Color color;

class PieceColor
{
protected:
    Color color;

public:
    PieceColor(Color c);
    Color getColor() const;
};
class Piece
{
protected:
    Color color;

public:
    Piece(Color c);
    Color getColor() const;
};
class Pawn : public Piece
{
public:
    Pawn(Color c) : Piece(c) {}
};

#endif // PIECES_H