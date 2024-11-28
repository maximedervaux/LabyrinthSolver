#include "../include/resolver.h"

#include <stdio.h>

#include "../include/maze.h"
#include <stdlib.h>

static Cellule** mastack = NULL;
static int stacktop = 0;

Direction randDirectionForSolver(Cellule* cellule, Maze* maze) {
    int validDirections[4];
    int count = 0;

    if (cellule->coordonate.y > 0 &&
        !maze->grid[cellule->coordonate.y - 1][cellule->coordonate.x].visite &&
        !maze->grid[cellule->coordonate.y - 1][cellule->coordonate.x].wallBottom) {
        validDirections[count++] = UP;
    }

    if (cellule->coordonate.x < maze->width - 1 &&
        !maze->grid[cellule->coordonate.y][cellule->coordonate.x + 1].visite &&
        !cellule->wallRight) {
        validDirections[count++] = RIGHT;
    }

    if (cellule->coordonate.y < maze->height - 1 &&
        !maze->grid[cellule->coordonate.y + 1][cellule->coordonate.x].visite &&
        !cellule->wallBottom) {
        validDirections[count++] = DOWN;
    }

    if (cellule->coordonate.x > 0 &&
        !maze->grid[cellule->coordonate.y][cellule->coordonate.x - 1].visite &&
        !maze->grid[cellule->coordonate.y][cellule->coordonate.x - 1].wallRight) {
        validDirections[count++] = LEFT;
    }

    if (count > 0) {
        return validDirections[rand() % count];
    }

    return -1;
}

void startBacktracking(Maze* maze) {
    if (mastack) {
        free(mastack);
    }

    mastack = malloc(sizeof(Cellule*) * maze->width * maze->height);
    stacktop = 0;

    Cellule* startCellule = &maze->grid[maze->start.y][maze->start.x];
    mastack[stacktop++] = startCellule;
    startCellule->visite = 2;
}

int stepBacktracking(Maze* maze) {


    Cellule* cellule = mastack[stacktop - 1];

    if (cellule->coordonate.x == maze->end.x && cellule->coordonate.y == maze->end.y) {
        if (mastack) {
            free(mastack);
            mastack = NULL;
        }
        return 1;
    }

    Direction direction = randDirectionForSolver(cellule, maze);

    if (direction != -1) {

        Cellule* nextCellule = NULL;

        switch (direction) {
            case UP:
                nextCellule = &maze->grid[cellule->coordonate.y - 1][cellule->coordonate.x];
                break;
            case DOWN:
                nextCellule = &maze->grid[cellule->coordonate.y + 1][cellule->coordonate.x];
                break;
            case RIGHT:
                nextCellule = &maze->grid[cellule->coordonate.y][cellule->coordonate.x + 1];
                break;
            case LEFT:
                nextCellule = &maze->grid[cellule->coordonate.y][cellule->coordonate.x - 1];
                break;
        }


        if (nextCellule && nextCellule->visite == 0) {
            nextCellule->visite = 2; // en cours de visite
            mastack[stacktop++] = nextCellule;
        }
    } else {
        cellule->visite = -1; // visité (impasse)
        stacktop--;
    }

    return 0;
}


int resolve(Maze* maze) {
    printf("\nRésolution du labyrinthe...\n");
    startBacktracking(maze);
    printf("Labyrinthe résolu !\n");
    return 0;
}