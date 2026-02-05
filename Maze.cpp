#include "Maze.h"
#include <stdexcept>
#include <iostream>
#include <memory>

Maze::Maze(const std::vector<std::string>& grid) {
    setData(grid);
}


void Maze::setData(const std::vector<std::string>& grid) {
    ValidInput(grid);
    rows_ = grid.size();
    columns_ = grid[0].size();
    grid_.assign(rows_, std::vector<int>(columns_));
    for (std::size_t i = 0; i < rows_; i++) {
        for (std::size_t j = 0; j < columns_; j++) {
            grid_[i][j] = charToInt(grid[i][j]);
            if(grid[i][j] == 'S') start_ = {i,j};
            else if(grid[i][j] == 'E') end_ = {i,j};
        }
    }
}

void Maze::ValidInput(const std::vector<std::string>& grid) const {
    if (grid.empty()) {
        throw std::invalid_argument("Grid should not be empty");
    }
    std::size_t colNum = grid[0].size();
    int startCount = 0;
    int exitCount = 0;
    for (const auto& row : grid) {
        if (row.size() != colNum) {
            throw std::invalid_argument("All rows should have equal length");
        }
        for (char element : row) {
            if (element != '#' && element != '.' && element != 'S' && element != 'E' ) {
                throw std::invalid_argument("Grid must contain only: # . S E");
            }
            if (element == 'S') startCount++;
            if (element == 'E') exitCount++;
        }
    }
    if (startCount != 1 || exitCount != 1) {
        throw std::invalid_argument("There should only be 1 Start and 1 End");
    }
}

int Maze::charToInt(char c) const {
    switch (c) {
        case '#': return 0;
        case '.': return 1;
        case 'S': return 2;
        case 'E': return 3;
        default:
            throw std::invalid_argument("Invalid maze character");
    }
}

bool Maze::isWall(std::size_t row, std::size_t col) const {
    return (grid_[row][col] == 0);
}

bool Maze::isExit(std::size_t row, std::size_t col) const {
    return (grid_[row][col] == 3);
}

std::size_t Maze::totalRows() const {
    return rows_;
}

std::size_t Maze::totalCols() const {
    return columns_;
}

std::pair<std::size_t, std::size_t> Maze::start() const {
    return start_;
}

std::pair<std::size_t, std::size_t> Maze::end() const {
    return end_;
}


void Maze::printNumericMaze() const {
    std::cout << "\n";
    for (const auto& row : grid_) {
        std::cout << " ";
        for (const auto& digit : row) {
            std::cout << digit << " ";
        }
        std::cout << "\n";
    }
}





