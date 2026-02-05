#ifndef DFS_H
#define DFS_H

#include "Solver.h"
#include <stack>
#include <memory>
#include <array>

class DFS : public Solver {
private: 
    std::stack<std::pair<std::size_t, std::size_t>> stack_;
    static constexpr std::array<std::pair<int,int>,4> directions_ {
        {{+1 , 0}, {0, +1}, {-1, 0}, {0, -1}}
    };
public:
    explicit DFS(Maze& maze);
    void pushNeighbours(std::size_t row, std::size_t col);
    bool dfs();
};

#endif // DFS_H
