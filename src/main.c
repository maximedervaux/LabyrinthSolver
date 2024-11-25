#include <stdio.h>
#include <time.h>
#include <unistd.h>

#include "../include/maze.h"
#include "../include/resolver.h"
#include "stdlib.h"


int main(void) {
    int width = 10 ;
    int height = 10;
    srand(time(NULL));

    Maze *monlabirynth = createMaze(width, height);
    backTrackingGenerator(monlabirynth, &monlabirynth->grid[monlabirynth->start.y][monlabirynth->start.x]);
    resetVisite(monlabirynth);


    printf("----------------------------\n");
    printf("Labyrinthe généré :\n");
    printf("----------------------------\n");

    printMaze(monlabirynth);


    usleep(1000000);

    resolve(monlabirynth);
    freeMaze(monlabirynth);

    return 0;
}
