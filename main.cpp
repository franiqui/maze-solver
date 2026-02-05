#include "Maze.h"
#include "Solver.h"
#include "DFS.h"

#include <iostream>
#include <vector>
#include <string>

int main() {
    std::vector<std::string> example = {
        "#######",
        "#S...##",
        "#####E#",
        "#.....#",
        "#######"
    };

    Maze maze(example);
    maze.printNumericMaze();

    DFS dfs(maze);

    bool found = dfs.dfs();
    if (found) {
        std::cout << "Solution found\n";
    } else {
        std::cout << "Solution not found\n";
    }

    return 0;
}
