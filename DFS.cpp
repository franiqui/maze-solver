#include "DFS.h"

DFS::DFS(Maze& maze) : Solver(maze) {};

void DFS::pushNeighbours(std::size_t row, std::size_t col) {
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
        visit(nextRow, nextCol);
        stack_.push({nextRow,nextCol});
    }
}

bool DFS::dfs() {
    stack_.push(maze_.start());
    visit(maze_.start().first, maze_.start().second);
    while(!stack_.empty()) {
        auto [r, c] = stack_.top();
        stack_.pop();
        if (maze_.isExit(r,c)) {
            return true;
        }
        pushNeighbours(r, c);
    }
    return false;
}