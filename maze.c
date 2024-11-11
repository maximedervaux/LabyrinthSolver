//
// Created by Maxime Dervaux on 11/11/2024.
//

#include "include/maze.h"

#include <stdio.h>
#include <stdlib.h>


Maze* createMaze(int width, int height) {
    Maze* maze = malloc(sizeof(Maze));
    maze->width = width;
    maze->height = height;

    maze->grid = malloc(height * sizeof(int*));
    for (int i = 0; i < height; i++) {
        maze->grid[i] = malloc(width * sizeof(int));
    }

    for (int i = 0; i < height; i++) {
        for (int j = 0; j < width; j++) {
            maze->grid[i][j] = 1;
        }
    }

    //TODO Ajouter un peu d'aleatoire
    maze->start.x = 0;
    maze->start.y = 0;
    maze->end.x = width - 1;
    maze->end.y = height - 1;

    return maze;

}

void printMaze(Maze* maze) {
    for (int i = 0; i < maze->width; i++) {
        for (int j = 0; j < maze->height; j++) {
            printf("%d ", maze->grid[i][j]);
        }
        printf("\n");
    }
}


void freeMaze(Maze *maze) {
    for (int i = 0; i < maze->height; i++) {
        free(maze->grid[i]);
    }
    free(maze->grid);
    free(maze);
}

