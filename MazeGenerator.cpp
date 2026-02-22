#include "MazeGenerator.h"
#include <vector>
#include <string>
#include <algorithm>
#include <stdexcept>

MazeGenerator::MazeGenerator(std::size_t rows, std::size_t cols) : generator_(std::random_device{}()){
    if (rows <= 3 || cols <= 3) {
        throw std::invalid_argument("Row and/or column number should be at least four to correctly generate a maze");
    }
    if (rows % 2 == 0) rows++;
    if (cols % 2 == 0) cols++;
    rows_ = rows;
    columns_ = cols;
    grid_ = std::vector<std::string>(rows, std::string(cols, '#'));
    visited_ = std::vector<std::vector<bool>>(rows, std::vector<bool>(cols, false));
    distances_ = std::vector<std::vector<int>>(rows, std::vector<int>(cols, -1));
}

std::vector<std::pair<int, int>> MazeGenerator::possibleDirections() {
    std::vector<std::pair<int, int>> directions = {{0, -2}, {2, 0}, {0, 2}, {-2, 0}};
    std::shuffle(directions.begin(), directions.end(), generator_);
    return directions;
}

bool MazeGenerator::canMove(int nextRow, int nextCol) {
    if (nextRow < 0 || nextRow >= static_cast<int>(rows_) || nextCol < 0 || nextCol >= static_cast<int>(columns_)) {
        return false;
    }
    return true;
}

bool MazeGenerator::isVisited(std::size_t row, std::size_t col) {
    return visited_[row][col];
}

std::pair<std::size_t, std::size_t> MazeGenerator::selectRandomStart() {
    std::vector<std::pair<std::size_t, std::size_t>> possibleStartPositions;
    possibleStartPositions.reserve((rows_ / 2) * (columns_ / 2));
    for (std::size_t r = 1; r < rows_; r+=2) {
        possibleStartPositions.push_back({r,1});
        possibleStartPositions.push_back({r,columns_-2});
    }
    for (std::size_t c = 3; c < columns_ - 2; c+=2) {
        possibleStartPositions.push_back({1,c});
        possibleStartPositions.push_back({rows_-2,c});
    }
    std::uniform_int_distribution<int> distribution(0,possibleStartPositions.size() - 1);
    return possibleStartPositions[distribution(generator_)];
}


void MazeGenerator::DFSGeneration() {
    start_ = selectRandomStart();
    stack_.push(start_);
    grid_[start_.first][start_.second] = 'S';
    while (!stack_.empty()) {
        auto [r, c] = stack_.top();
        visited_[r][c] = true;
        bool moved = false;
        std::vector<std::pair<int, int>> directions = possibleDirections();
        for (auto dir : directions) { // Check if it continues shuffling iteration after iteration
            int possibleRow = static_cast<int>(r) + dir.first;
            int possibleCol = static_cast<int>(c) + dir.second;
            if (canMove(possibleRow, possibleCol)) {
                std::size_t newRow = static_cast<std::size_t>(possibleRow);
                std::size_t newCol = static_cast<std::size_t>(possibleCol);
                if (!isVisited(newRow, newCol)) {
                    moved = true;
                    std::size_t wallRow = (r + newRow) / 2;
                    std::size_t wallCol = (c + newCol) / 2;
                    grid_[newRow][newCol] = '.';
                    grid_[wallRow][wallCol] = '.';
                    stack_.push({newRow, newCol});
                    break;
                }
            }
        }
        if (!moved) {
            stack_.pop();
        }
    }
}

std::pair<std::size_t, std::size_t> MazeGenerator::findFarthestCell() {
    std::pair<std::size_t, std::size_t> farthestCell = start_;
    queue_.push(start_);
    distances_[start_.first][start_.second] = 0;
    std::vector<std::pair<int, int>> dirs = {{0,1}, {-1,0}, {0,-1}, {1,0}};
    while (!queue_.empty()) {
        auto [r, c] = queue_.front();
        if (distances_[r][c] > distances_[farthestCell.first][farthestCell.second] && (r==1 || r==rows_-2 || c==1 || c==columns_-2)) {
            farthestCell = {r,c};
        }
        queue_.pop();
        for (auto dir : dirs) {
            int possibleRow = static_cast<int>(r) + dir.first;
            int possibleCol = static_cast<int>(c) + dir.second;
            if (canMove(possibleRow, possibleCol)) {
                std::size_t newRow = static_cast<std::size_t>(possibleRow);
                std::size_t newCol = static_cast<std::size_t>(possibleCol);
                if (grid_[newRow][newCol] == '.' && distances_[newRow][newCol] == -1) {
                    queue_.push({newRow,newCol});
                    distances_[newRow][newCol] = distances_[r][c] + 1;
                }
            }
        }
    }
    return farthestCell;
}

void MazeGenerator::setExit() {
    auto [r, c] = findFarthestCell();
    grid_[r][c] = 'E';
}

Maze MazeGenerator::generate() {
    DFSGeneration();
    setExit();
    return Maze(grid_);
}
