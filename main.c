#include <stdio.h>
#include <time.h>

#include "include/maze.h"
#include "stdlib.h"


int main(void) {
    int width = 5 ;
    int height = 5;
    srand(time(NULL));

    Maze *monlabirynth = createMaze(width, height);
    backTracking(monlabirynth, &monlabirynth->grid[monlabirynth->start.y][monlabirynth->start.x]);

    printf("----------------------------\n");
    printf("Labyrinthe généré :\n");
    printf("----------------------------\n");

    printMaze(monlabirynth);
    freeMaze(monlabirynth);
    return 0;
}
