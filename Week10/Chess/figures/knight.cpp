#include <cmath>
#include <iostream>
#include "figure.hpp"
#include "knight.hpp"
#include "../color.hpp"
#include "../board.hpp"
#include "../position.hpp"

Knight::Knight(const Color &color) : Figure(color) {}

std::ostream &Knight::print(std::ostream &out) const
{
    return out << (this->getColor() == Color::WHITE ? "White Knight" : "Black Knight");
}

bool Knight::canMove(const Board &board, const Position &from, const Position &to)
{
    return board.get(from) == this                                                            // we occupy 'from'
           && abs(from.getRank() - to.getRank()) > 0                                          // we shift vertically
           && abs(from.getFile() - to.getFile()) > 0                                          // we shift horizontally
           && (board.get(to) == nullptr || board.get(to)->getColor() != this->getColor())     // we can occupy 'to'
           && (abs(from.getRank() - to.getRank()) + abs(from.getFile() - to.getFile())) == 3; // we move 3 boxes exactly
}
