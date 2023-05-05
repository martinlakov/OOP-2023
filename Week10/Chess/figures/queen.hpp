#ifndef _QUEEN_HPP_
#define _QUEEN_HPP_

#include <iostream>
#include "figure.hpp"
#include "../board.hpp"
#include "../color.hpp"
#include "../position.hpp"

class Queen : public Figure
{
private:
    static bool hasObstaclesAlongTheWay(const Board &board, const Position &from, const Position &to);

protected:
    std::ostream &print(std::ostream &out) const override;

public:
    Queen(const Color &color);

    bool canMove(const Board &board, const Position &from, const Position &to);
};

#endif