#ifndef _KING_HPP_
#define _KING_HPP_

#include <iostream>
#include "figure.hpp"
#include "../board.hpp"
#include "../color.hpp"
#include "../position.hpp"

class King : public Figure
{
protected:
    std::ostream &print(std::ostream &out) const override;

public:
    King(const Color &color);

    bool canMove(const Board &board, const Position &from, const Position &to);
};

#endif