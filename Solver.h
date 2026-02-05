#ifndef SOLVER_H
#define SOLVER_H

#include "Maze.h"
#include <cstddef>
#include <queue>
#include <vector>

class Solver {
protected:
    Maze& maze_;
    std::vector<std::vector<bool>> visited_;
    std::vector<std::pair<std::size_t, std::size_t>> solution_;

public:
    explicit Solver(Maze& maze);

    bool moveUp(std::size_t row, std::size_t col);
    bool moveRight(std::size_t row, std::size_t col);
    bool moveDown(std::size_t row, std::size_t col);
    bool moveLeft(std::size_t row, std::size_t col);

    bool canMove(int nextRow, int nextCol);

    void visit(std::size_t row, std::size_t col);
    bool isVisited(std::size_t row, std::size_t col);
};

#endif // SOLVER_H