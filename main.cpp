#include "Maze.h"
#include "Solver.h"
#include "DFS.h"
#include "BFS.h"

#include <iostream>
#include <vector>
#include <string>

int main() {
    std::vector<std::string> example = {
        "#########################",
        "#S......................#",
        "#.###################..##",
        "#.###################..##",
        "#.###################..##",
        "#..E#################..##",
        "#.......................#",
        "#########################"
        };

    Maze maze(example);
    maze.printWithoutSolution();

    DFS dfs(maze);
    BFS bfs(maze);

    bool foundDFS = dfs.dfs();
    if (foundDFS) {
        std::cout << "Solution found with DFS: \n";
        maze.printWithSolution(dfs.solution());
    } else {
        std::cout << "Solution not found\n";
    }

    bool foundBFS = bfs.bfs();
    if (foundBFS) {
        std::cout << "Solution found with BFS: \n";
        maze.printWithSolution(bfs.solution());
    } else {
        std::cout << "Solution not found\n";
    }

    return 0;
}
