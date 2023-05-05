#include <cmath>
#include <vector>
#include <cassert>
#include <iostream>
#include "utils.hpp"
#include "board.hpp"
#include "position.hpp"

Position::Position(char file, int rank) : Position((int)(file - 'A'), rank - 1) {}

Position::Position(int file, int rank)
{
    assert(file > -1 && file < BOARD_SIZE);
    this->file = file;

    assert(rank > -1 && rank < BOARD_SIZE);
    this->rank = rank;
}

int Position::getFile() const
{
    return this->file;
}

int Position::getRank() const
{
    return this->rank;
}

bool Position::isOnSameRank(const Position &other) const
{
    return this->rank == other.rank;
}

bool Position::isOnSameFile(const Position &other) const
{
    return this->file == other.file;
}

bool Position::isOnSameDiagonal(const Position &other) const
{
    return abs(this->file - other.file) == abs(this->rank - other.rank);
}

std::vector<Position> Position::inBetween(const Position &other) const
{
    assert(this->isOnSameFile(other) || this->isOnSameRank(other) || this->isOnSameDiagonal(other));

    const int r0 = this->getRank();
    const int r1 = other.getRank();
    const int dr = sign(r1 - r0);

    const int c0 = this->getFile();
    const int c1 = other.getFile();
    const int dc = sign(c1 - c0);

    std::vector<Position> result;
    for (int r = r0 + dr, c = c0 + dc; r != r1 || c != c1; r += dr, c += dc)
    {
        result.push_back(Position(r, c));
    }
    return result;
}

std::ostream &operator<<(std::ostream &out, const Position &position)
{
    return out << "[" << 'A' + position.file << ", " << position.rank + 1 << "]";
}