#include "BFS.h"
#include <algorithm>

BFS::BFS(Maze& maze) : Solver(maze) {};

void BFS::pushNeighbours(std::size_t row, std::size_t col) {
    for (auto [dr, dc] : directions_) {
        int possibleRow = static_cast<int>(row) + dr;
        int possibleCol = static_cast<int>(col) + dc;
        if (!canMove(possibleRow, possibleCol)) {
            continue;
        }
        std::size_t nextRow = static_cast<std::size_t>(possibleRow);
        std::size_t nextCol = static_cast<std::size_t>(possibleCol);
        if(isVisited(nextRow, nextCol)) {
            continue;
        }

        parent_[nextRow][nextCol] = {row, col};

        visit(nextRow, nextCol);
        queue_.push({nextRow,nextCol});
    }
}

bool BFS::bfs() {
    queue_.push(maze_.start());
    visit(maze_.start().first, maze_.start().second);
    while(!queue_.empty()) {
        auto [r, c] = queue_.front();
        queue_.pop();
        if (maze_.isExit(r,c)) {
            solution_.clear();
            std::pair<std::size_t,std::size_t> current{r,c};
            while (current != maze_.start()) {
                solution_.push_back(current);
                current = parent_[current.first][current.second];
            }
            solution_.push_back(maze_.start());
            std::reverse(solution_.begin(), solution_.end());
            return true;
        }
        pushNeighbours(r, c);
    }
    return false;
}