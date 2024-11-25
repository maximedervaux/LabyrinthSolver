//
// Created by Maxime Dervaux on 11/11/2024.
//

#include "../include/maze.h"
#include <unistd.h>

#include <stdio.h>
#include <stdlib.h>



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
            maze->grid[i][j].wallBottom= 1;
            maze->grid[i][j].wallRight = 1;

        }
    }

    //TODO Ajouter un peu d'aleatoire
    maze->start.x = 0;
    maze->start.y = 0;


    maze->grid[maze->start.y][maze->start.x].visite = 1;
    return maze;

}

void printMaze(Maze* maze) {
    for (int j = 0; j < maze->width; j++) {
        printf("+---");
    }
    printf("+\n");

    for (int i = 0; i < maze->height; i++) {
        printf("|");
        for (int j = 0; j < maze->width; j++) {
            if (maze->start.y == i && maze->start.x == j) {
                printf(" E ");
            } else if (maze->end.y == i && maze->end.x == j) {
                printf(" S ");
            } else if (maze->grid[i][j].visite == 2) {
                printf(" * ");
            } else {
                printf("   ");
            }
            printf(maze->grid[i][j].wallRight ? "|" : " ");
        }
        printf("\n");

        for (int j = 0; j < maze->width; j++) {
            printf("+");
            printf(maze->grid[i][j].wallBottom ? "---" : "   ");
        }
        printf("+\n");
    }
}

void freeMaze(Maze *maze) {
    for (int i = 0; i < maze->height; i++) {
        free(maze->grid[i]);
    }
    free(maze->grid);
    free(maze);
}

Direction randDirectionResolver(Cellule* cellule, Maze* maze) {
    int directions[4] = {UP, RIGHT, DOWN, LEFT};
    int validDirections[4];
    int count = 0;

    if (cellule->coordonate.y > 0 && !maze->grid[cellule->coordonate.y - 1][cellule->coordonate.x].visite)
        validDirections[count++] = UP;
    if (cellule->coordonate.x < maze->width - 1 && !maze->grid[cellule->coordonate.y][cellule->coordonate.x + 1].visite)
        validDirections[count++] = RIGHT;
    if (cellule->coordonate.y < maze->height - 1 && !maze->grid[cellule->coordonate.y + 1][cellule->coordonate.x].visite)
        validDirections[count++] = DOWN;
    if (cellule->coordonate.x > 0 && !maze->grid[cellule->coordonate.y][cellule->coordonate.x - 1].visite)
        validDirections[count++] = LEFT;

    if (count > 0) {
        return validDirections[rand() % count];
    }
    return -1;
}

int backTrackingGenerator(Maze* maze, Cellule* startCellule) {
    Cellule** mastack = malloc(sizeof(Cellule*) * maze->width * maze->height);
    int stacktop = 0;

    mastack[stacktop++] = startCellule;
    startCellule->visite = 1;

    while (stacktop > 0) {
        Cellule* cellule = mastack[stacktop - 1];
        Direction direction = randDirectionResolver(cellule, maze);

        if (direction != -1) {
            Cellule* nextCellule = NULL;

            switch (direction) {
                case UP:
                    nextCellule = &maze->grid[cellule->coordonate.y - 1][cellule->coordonate.x];
                    nextCellule->wallBottom = 0;
                break;
                case DOWN:
                    nextCellule = &maze->grid[cellule->coordonate.y + 1][cellule->coordonate.x];
                    cellule->wallBottom = 0;
                break;
                case RIGHT:
                    nextCellule = &maze->grid[cellule->coordonate.y][cellule->coordonate.x + 1];
                    cellule->wallRight = 0;
                break;
                case LEFT:
                    nextCellule = &maze->grid[cellule->coordonate.y][cellule->coordonate.x - 1];
                    nextCellule->wallRight = 0;
                break;
            }

            if (nextCellule) {

                maze->end = nextCellule->coordonate;
                nextCellule->visite = 1;
                mastack[stacktop++] = nextCellule;


                //printMaze(maze);
                // usleep(500000);
            }
        } else {
            stacktop--;
        }
    }

    free(mastack);
    return 0;
}

void resetVisite(Maze* maze) {
    for (int i = 0; i < maze->height; i++) {
        for (int j = 0; j < maze->width; j++) {
            maze->grid[i][j].visite = 0;
        }
    }
}