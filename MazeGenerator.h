#include <cstddef>
#include <vector>
#include <string>
#include <stack>
#include <queue>
#include <random>
#include "Maze.h"

class MazeGenerator {
private:
    std::vector<std::string> grid_;
    std::size_t rows_;
    std::size_t columns_;
    std::mt19937 generator_;
    std::pair<std::size_t, std::size_t> start_;
    std::stack<std::pair<std::size_t, std::size_t>> stack_;
    std::queue<std::pair<std::size_t, std::size_t>> queue_;
    std::vector<std::vector<bool>> visited_;
    std::vector<std::vector<int>> distances_;
public:
    explicit MazeGenerator(std::size_t rows, std::size_t cols);
    std::vector<std::pair<int, int>> possibleDirections();
    bool canMove(int nextRow, int nextCol);
    bool isVisited(std::size_t row, std::size_t col);
    std::pair<std::size_t, std::size_t> selectRandomStart();
    std::pair<std::size_t, std::size_t> startPosition();
    void DFSGeneration();
    std::pair<std::size_t, std::size_t> findFarthestCell();
    void setExit();
    Maze generate();
};