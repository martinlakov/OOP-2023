#ifndef _PAWN_HPP_
#define _PAWN_HPP_

#include <iostream>
#include "figure.hpp"
#include "../board.hpp"
#include "../color.hpp"
#include "../position.hpp"

class Pawn : public Figure
{
    const int direction;

    bool isFirstMove(const Position &position) const;
    bool isCapture(const Board &board, const Position &from, const Position &to) const;
    bool isRegularMove(const Board &board, const Position &from, const Position &to) const;

protected:
    std::ostream &print(std::ostream &out) const override;

public:
    Pawn(const Color &color);

    bool canMove(const Board &board, const Position &from, const Position &to);
};

#endif