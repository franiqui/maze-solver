#ifndef BFS_H
#define BFS_H

#include "Solver.h"
#include <queue>
#include <memory>
#include <array>

class BFS : public Solver {
private: 
    std::queue<std::pair<std::size_t, std::size_t>> queue_;
    static constexpr std::array<std::pair<int,int>,4> directions_ {
        {{+1 , 0}, {0, +1}, {-1, 0}, {0, -1}}
    };
public:
    explicit BFS(Maze& maze);
    void pushNeighbours(std::size_t row, std::size_t col);
    bool bfs();
};

#endif // BFS_H
