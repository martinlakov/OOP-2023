#include <cmath>
#include <iostream>
#include <vector>
#include "rook.hpp"
#include "figure.hpp"
#include "../color.hpp"
#include "../board.hpp"
#include "../position.hpp"

Rook::Rook(const Color &color) : Figure(color) {}

bool Rook::hasObstaclesAlongTheWay(const Board &board, const Position &from, const Position &to)
{
    std::vector<Position> path = from.inBetween(to);

    for (size_t idx = 0; idx < path.size(); ++idx)
    {
        if (board.get(path[idx]) != nullptr)
        {
            return true;
        }
    }

    return false;
}

std::ostream &Rook::print(std::ostream &out) const
{
    return out << (this->getColor() == Color::WHITE ? "White Rook" : "Black Rook");
}

bool Rook::canMove(const Board &board, const Position &from, const Position &to)
{
    return board.get(from) == this                                                         // we occupy 'from'
           && !this->hasObstaclesAlongTheWay(board, from, to)                              // no obstacles along the way
           && (from.isOnSameFile(to) || from.isOnSameRank(to))                             // we either shift horizontally or vertically
           && (board.get(to) == nullptr || board.get(to)->getColor() != this->getColor()); // we can occupy 'to'
}
