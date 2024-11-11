#include <stdio.h>
#include "include/maze.h"


int main(void) {
    int width = 5 ;
    int height = 5;

    Maze *monlabirynth = createMaze(width, height);
    printMaze(monlabirynth);
    freeMaze(monlabirynth);
    return 0;
}
