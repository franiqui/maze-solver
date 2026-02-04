#include "Maze.h"
#include <iostream>
#include <vector>
#include <string>

int main() {
    std::vector<std::string> example = {
        "#######",
        "#S...##",
        "###.#E#",
        "#.....#",
        "#######"
    };

    Maze maze(example);
    maze.printNumericMaze();
}
