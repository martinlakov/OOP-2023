#include <cmath>
#include <iostream>
#include <vector>
#include "bishop.hpp"
#include "figure.hpp"
#include "../color.hpp"
#include "../board.hpp"
#include "../position.hpp"

Bishop::Bishop(const Color &color) : Figure(color) {}

bool Bishop::hasObstaclesAlongTheWay(const Board &board, const Position &from, const Position &to)
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

std::ostream &Bishop::print(std::ostream &out) const
{
    return out << (this->getColor() == Color::WHITE ? "White Bishop" : "Black Bishop");
}

bool Bishop::canMove(const Board &board, const Position &from, const Position &to)
{
    return board.get(from) == this                                                         // we occupy 'from'
           && (from.isOnSameDiagonal(to))                                                  // we can only move diagonally
           && !this->hasObstaclesAlongTheWay(board, from, to)                              // no obstacles along the way
           && (board.get(to) == nullptr || board.get(to)->getColor() != this->getColor()); // we can occupy 'to'
}
