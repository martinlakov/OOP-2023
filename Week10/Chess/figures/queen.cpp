#include <cmath>
#include <iostream>
#include <vector>
#include "queen.hpp"
#include "figure.hpp"
#include "../color.hpp"
#include "../board.hpp"
#include "../position.hpp"

Queen::Queen(const Color &color) : Figure(color) {}

bool Queen::hasObstaclesAlongTheWay(const Board &board, const Position &from, const Position &to)
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

std::ostream &Queen::print(std::ostream &out) const
{
    return out << (this->getColor() == Color::WHITE ? "White Queen" : "Black Queen");
}

bool Queen::canMove(const Board &board, const Position &from, const Position &to)
{
    return board.get(from) == this                                                           // we occupy 'from'
           && !this->hasObstaclesAlongTheWay(board, from, to)                                // no obstacles along the way
           && (board.get(to) == nullptr || board.get(to)->getColor() != this->getColor())    // we can occupy 'to'
           && (from.isOnSameFile(to) || from.isOnSameRank(to) || from.isOnSameDiagonal(to)); // we can move left/right, front/back & diagonally
}
