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
class Rook : public Piece
{
    public:
    Rook(Color c);
};
class Knight : public Piece
{
    public:
    Knight(Color c);
};
class Bishop : public Piece
{
    public:
    Bishop(Color c);
};
class Queen : public Piece
{
    public:
    Queen(Color c);
};
class King : public Piece
{
    public:
    King(Color c);
};

#endif // PIECES_H