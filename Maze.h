#ifndef MAZE_H
#define MAZE_H

#include <vector>
#include <string>
#include <cstddef>

class Maze {
private:
    std::vector<std::vector<int>> grid_;
    std::size_t rows_;
    std::size_t columns_;

public:
    explicit Maze(const std::vector<std::string>& grid);
    
    void setData(const std::vector<std::string>& grid);
    void ValidInput(const std::vector<std::string>& grid) const;

    int charToInt(char c) const;

    void printNumericMaze() const;
}; 
#endif // MAZE_H