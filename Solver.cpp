#include "Solver.h"

Solver::Solver(Maze& maze) : maze_(maze) {
    visited_.assign(maze_.totalRows(), std::vector<bool>(maze_.totalCols()));
    parent_.assign(maze_.totalRows(), std::vector<std::pair<std::size_t, std::size_t>>(maze_.totalCols(),{0,0}));
}

bool Solver::canMove(int nextRow, int nextCol) {
    if (nextRow >= static_cast<int>(maze_.totalRows()) || nextRow < 0 || nextCol >= static_cast<int>(maze_.totalCols()) || nextCol < 0) {
        return false;
    }
    return (maze_.isWall(nextRow, nextCol) == false);
}

void Solver::visit(std::size_t row, std::size_t col) {
    visited_[row][col] = 1;
}

bool Solver::isVisited(std::size_t row, std::size_t col) {
    return visited_[row][col];
}

std::vector<std::pair<std::size_t, std::size_t>> Solver::solution() const {
    return solution_;
}
