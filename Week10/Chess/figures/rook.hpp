#ifndef _ROOK_HPP_
#define _ROOK_HPP_

#include <iostream>
#include "figure.hpp"
#include "../board.hpp"
#include "../color.hpp"
#include "../position.hpp"

class Rook: public Figure {
private:
    static bool hasObstaclesAlongTheWay(const Board& board, const Position& from, const Position& to);

protected:
    std::ostream& print(std::ostream& out) const override;

public:
    Rook(const Color& color);
    
    bool canMove(const Board& board, const Position& from, const Position& to);
};

#endif