#include "Solver.h"

Solver::Solver(Maze& maze) : maze_(maze) {
    visited_.assign(maze_.totalRows(), std::vector<bool>(maze_.totalCols()));
}

bool Solver::moveUp(std::size_t row, std::size_t col) {
    if (row == 0) return false;
    return (maze_.isWall(row - 1, col) == false);
}

bool Solver::moveRight(std::size_t row, std::size_t col) {
    if (col + 1 == maze_.totalCols()) return false;
    return (maze_.isWall(row, col + 1) == false);
}

bool Solver::moveDown(std::size_t row, std::size_t col) {
    if (row + 1 == maze_.totalRows()) return false;
    return (maze_.isWall(row + 1, col) == false);
}

bool Solver::moveLeft(std::size_t row, std::size_t col) {
    if (col == 0) return false;
    return (maze_.isWall(row, col - 1) == false);
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
