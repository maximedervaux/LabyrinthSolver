//
// Created by Maxime Dervaux on 11/11/2024.
//

#include "include/maze.h"

#include <stdio.h>
#include <stdlib.h>
#include <time.h>


typedef enum {
    UP = 0,
    RIGHT = 1,
    DOWN = 2,
    LEFT = 3
} Direction;


Maze* createMaze(int width, int height) {
    Maze* maze = malloc(sizeof(Maze));
    maze->width = width;
    maze->height = height;

    maze->grid = malloc(height * sizeof(Cellule*));
    for (int i = 0; i < height; i++) {
        maze->grid[i] = malloc(width * sizeof(Cellule));
    }

    for (int i = 0; i < height; i++) {
        for (int j = 0; j < width; j++) {
            maze->grid[i][j].visite = 0;
            maze->grid[i][j].coordonate.x = j;
            maze->grid[i][j].coordonate.y = i;
            maze->grid[i][j].walls.top = 1;
            maze->grid[i][j].walls.bottom = 1;
            maze->grid[i][j].walls.left = 1;
            maze->grid[i][j].walls.right = 1;
        }
    }

    //TODO Ajouter un peu d'aleatoire
    maze->start.x = 0;
    maze->start.y = 0;


    maze->grid[maze->start.y][maze->start.x].visite = 1;
    maze->grid[maze->end.y][maze->end.x].visite = 1;
    return maze;

}

void printMaze(Maze* maze) {
    for (int i = 0; i < maze->height; i++) {
        for (int j = 0; j < maze->width; j++) {
            printf("+");
            printf(maze->grid[i][j].walls.top ? "---" : "   ");
        }
        printf("+\n");

        for (int j = 0; j < maze->width; j++) {
            printf(maze->grid[i][j].walls.left ? "|" : " ");
            printf(" %d ",maze->grid[i][j].visite);
        }
        printf("|\n");
    }

    for (int j = 0; j < maze->width; j++) {
        printf("+---");
    }
    printf("+\n");
}


void freeMaze(Maze *maze) {
    for (int i = 0; i < maze->height; i++) {
        free(maze->grid[i]);
    }
    free(maze->grid);
    free(maze);
}

void backTracking(Maze* maze, Cellule* startCellule) {
    Cellule **mastack = malloc(sizeof(Cellule*) * maze->width * maze->height);

    int stacktop = 0;
    mastack[stacktop++] = startCellule;


}


Direction randDirection(Cellule* cellule) {
    srand(time(NULL));
    int directions[4] = {UP, DOWN, RIGHT, LEFT};
    int validDirections[4];  // CA VA PERMETTRE DE GERER LES BORDS DU MAZE
    int count = 0;

    if (cellule->coordonate.y > 0)
        validDirections[count++] = UP;
    if (cellule->coordonate.x < maze->width - 1)
        validDirections[count++] = RIGHT;
    if (cellule->coordonate.y < maze->height - 1)
        validDirections[count++] = DOWN;
    if (cellule->coordonate.x > 0)
        validDirections[count++] = LEFT;

    if (count > 0) {
        return validDirections[rand() % count];
    }
    return -1;
}
