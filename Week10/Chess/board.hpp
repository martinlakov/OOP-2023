#ifndef _BOARD_HPP_
#define _BOARD_HPP_

class Board;

#include <iostream>
#include "color.hpp"
#include "position.hpp"
#include "figures/figure.hpp"

const size_t BOARD_SIZE = 8;

class Board
{
private:
    Color turn;
    Figure *board[BOARD_SIZE][BOARD_SIZE];

    void initializeFigures(const Color& color);

public:
    Board();

    Figure *get(const Position &position) const;
    void move(const Position &from, const Position &to);

    friend std::ostream &operator<<(std::ostream &out, const Board &board);
};

#endif