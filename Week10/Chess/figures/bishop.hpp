#ifndef _BISHOP_HPP_
#define _BISHOP_HPP_

#include <iostream>
#include "figure.hpp"
#include "../board.hpp"
#include "../color.hpp"
#include "../position.hpp"

class Bishop : public Figure
{
private:
    static bool hasObstaclesAlongTheWay(const Board &board, const Position &from, const Position &to);

protected:
    std::ostream &print(std::ostream &out) const override;

public:
    Bishop(const Color &color);

    bool canMove(const Board &board, const Position &from, const Position &to);
};

#endif