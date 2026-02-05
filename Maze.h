#ifndef MAZE_H
#define MAZE_H

#include <vector>
#include <string>
#include <cstddef>
#include <memory>

class Maze {
private:
    std::vector<std::vector<int>> grid_;
    std::size_t rows_;
    std::size_t columns_;
    std::pair<std::size_t, std::size_t> start_;
    std::pair<std::size_t, std::size_t> end_;

public:
    explicit Maze(const std::vector<std::string>& grid);
    
    void setData(const std::vector<std::string>& grid);
    void ValidInput(const std::vector<std::string>& grid) const;

    int charToInt(char c) const;

    bool isWall(std::size_t row, std::size_t col) const;
    bool isExit(std::size_t row, std::size_t col) const;

    std::size_t totalRows() const;
    std::size_t totalCols() const;

    std::pair<std::size_t, std::size_t> start() const;
    std::pair<std::size_t, std::size_t> end() const;

    void printNumericMaze() const;

}; 
#endif // MAZE_H