#include <iomanip>
#include "board.hpp"
#include "figures/king.hpp"
#include "figures/pawn.hpp"
#include "figures/rook.hpp"
#include "figures/queen.hpp"
#include "figures/bishop.hpp"
#include "figures/knight.hpp"

Board::Board() : board{{nullptr}}
{
    this->turn == Color::WHITE;
    this->initializeFigures(Color::WHITE);
    this->initializeFigures(Color::BLACK);
}

void Board::initializeFigures(const Color &color)
{
    size_t pawnsRank = color == Color::WHITE ? 1 : 6;
    size_t figuresRank = color == Color::WHITE ? 0 : 7;

    this->board[figuresRank][0] = new Rook(color);
    this->board[figuresRank][1] = new Knight(color);
    this->board[figuresRank][2] = new Bishop(color);
    this->board[figuresRank][3] = new Queen(color);
    this->board[figuresRank][4] = new King(color);
    this->board[figuresRank][5] = new Bishop(color);
    this->board[figuresRank][6] = new Knight(color);
    this->board[figuresRank][7] = new Rook(color);

    for (size_t file = 0; file < BOARD_SIZE; ++file)
    {
        this->board[pawnsRank][file] = new Pawn(color);
    }
}

Figure *Board::get(const Position &position) const
{
    return this->board[position.getRank()][position.getFile()];
}

void Board::move(const Position &from, const Position &to)
{
    Figure *figure = this->get(from);

    if (figure == nullptr || !figure->canMove(*this, from, to))
    {
        throw std::invalid_argument("illegal move");
    }

    this->board[to.getRank()][to.getFile()] = figure;
    this->board[from.getRank()][from.getFile()] = nullptr;
}

std::ostream &operator<<(std::ostream &out, const Board &board)
{
    out << std::setw(129) << std::setfill('-') << "" << std::endl;
    out << "| - |      A       |      B       |      C       |      D       |      E       |      F       |      G       |      H       | - |" << std::endl;
    out << std::setw(129) << std::setfill('-') << "" << std::endl;

    for (int rank = 7; rank >= 0; --rank)
    {
        out << "| " << rank + 1 << " |";
        for (size_t file = 0; file < 8; ++file)
        {
            Figure *figure = board.board[rank][file];

            if (figure == nullptr)
            {
                out << std::setw(14) << std::setfill(' ') << "" << "|";
            }
            else
            {
                out << std::setw(14) << std::setfill(' ') << *figure << "|";
            }
        }

        out << " " << rank + 1 << " |" << std::endl;
        out << std::setw(129) << std::setfill('-') << "" << std::endl;
    }

    out << "| - |      A       |      B       |      C       |      D       |      E       |      F       |      G       |      H       | - |" << std::endl;
    out << std::setw(129) << std::setfill('-') << "" << std::endl;

    return out;
}
