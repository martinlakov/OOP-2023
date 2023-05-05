#include <cmath>
#include <iostream>
#include "pawn.hpp"
#include "figure.hpp"
#include "../utils.hpp"
#include "../color.hpp"
#include "../board.hpp"
#include "../position.hpp"

std::ostream &Pawn::print(std::ostream &out) const
{
    return out << (this->getColor() == Color::WHITE ? "White Pawn" : "Black Pawn");
}

bool Pawn::isFirstMove(const Position &position) const
{
    return (this->color == Color::WHITE && position.getRank() == 1) || (this->color == Color::BLACK && position.getRank() == 6);
}

bool Pawn::isCapture(const Board &board, const Position &from, const Position &to) const
{
    return abs(from.getFile() - to.getFile()) == 1              // one to the left/right
           && board.get(to)->getColor() != this->getColor()     // we can capture 'to'
           && sign(from.getRank() - to.getRank()) == direction; // move is in the right direction
}

bool Pawn::isRegularMove(const Board &board, const Position &from, const Position &to) const
{
    return board.get(to) == nullptr                                                            // we can occupy 'to'
           && from.getFile() == to.getFile()                                                   // no movement to the left/right
           && sign(from.getRank() - to.getRank()) == direction                                 // move is in the right direction
           && between(abs(from.getRank() - to.getRank()), 1, this->isFirstMove(from) ? 2 : 1); // we only move one/two steps
}

Pawn::Pawn(const Color &color) : Figure(color), direction(color == Color::WHITE ? -1 : 1) {}

bool Pawn::canMove(const Board &board, const Position &from, const Position &to)
{
    return board.get(from) == this && (this->isCapture(board, from, to) || this->isRegularMove(board, from, to));
}
