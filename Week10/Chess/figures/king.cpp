#include <cmath>
#include <iostream>
#include <vector>
#include "king.hpp"
#include "figure.hpp"
#include "../color.hpp"
#include "../board.hpp"
#include "../position.hpp"

King::King(const Color &color) : Figure(color) {}

std::ostream &King::print(std::ostream &out) const
{
    return out << (this->getColor() == Color::WHITE ? "White King" : "Black King");
}

bool King::canMove(const Board &board, const Position &from, const Position &to)
{
    return board.get(from) == this                                                            // we occupy 'from'
           && (board.get(to) == nullptr || board.get(to)->getColor() != this->getColor())     // we can occupy 'to'
           && (from.isOnSameFile(to) || from.isOnSameRank(to) || from.isOnSameDiagonal(to))   // we can move left/right, front/back & diagonally
           && (abs(from.getFile() - to.getFile()) + abs(from.getRank() - to.getRank())) == 1; // we can only move one square
}
