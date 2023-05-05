#ifndef _POSITION_HPP_
#define _POSITION_HPP_

#include <iostream>
#include <vector>

class Position
{
private:
    int file; // A - H
    int rank; // 1 - 8

public:
    Position(int file, int rank);
    Position(char file, int rank);

    int getFile() const;
    int getRank() const;
    bool isOnSameRank(const Position &other) const;
    bool isOnSameFile(const Position &other) const;
    bool isOnSameDiagonal(const Position &other) const;
    std::vector<Position> inBetween(const Position &other) const;

    friend std::ostream &operator<<(std::ostream &out, const Position &position);
};

#endif