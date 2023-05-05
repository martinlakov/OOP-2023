#ifndef _FIGURE_HPP_
#define _FIGURE_HPP_

class Figure;

#include <iostream>
#include "../board.hpp"
#include "../color.hpp"
#include "../position.hpp"

class Figure
{
protected:
    const Color color;

protected:
    virtual std::ostream &print(std::ostream &out) const = 0;

public:
    Figure(const Color &color);

    Color getColor() const;
    virtual bool canMove(const Board &board, const Position &from, const Position &to) = 0;

    friend std::ostream &operator<<(std::ostream &out, const Figure &figure);
};

#endif