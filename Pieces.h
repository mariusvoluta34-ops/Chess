#ifndef PIECES_H
#define PIECES_H

enum Color
{
    WHITE,
    BLACK
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
    Pawn(Color c);
};

#endif // PIECES_H