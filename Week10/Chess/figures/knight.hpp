#ifndef _KNIGHT_HPP_
#define _KNIGHT_HPP_

#include <iostream>
#include "figure.hpp"
#include "../board.hpp"
#include "../color.hpp"
#include "../position.hpp"

class Knight : public Figure
{
protected:
    std::ostream &print(std::ostream &out) const override;

public:
    Knight(const Color &color);

    bool canMove(const Board &board, const Position &from, const Position &to);
};

#endif
