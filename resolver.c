//
// Created by Maxime Dervaux on 22/11/2024.
//

#include <stdio.h>
#include <stdlib.h>
#include "include/resolver.h"
#include <unistd.h>
#include "include/maze.h"


Direction randDirectionForSolver(Cellule* cellule, Maze* maze) {
    int validDirections[4];
    int count = 0;

    if (cellule->coordonate.y > 0 &&  // Vérifier que ce n'est pas en dehors du labyrinthe
       !maze->grid[cellule->coordonate.y - 1][cellule->coordonate.x].visite &&  // La cellule au-dessus n'a pas été visitée
       !maze->grid[cellule->coordonate.y - 1][cellule->coordonate.x].wallBottom) {  // La cellule au-dessus n'a pas de mur en bas
        validDirections[count++] = UP;
       }

    if (cellule->coordonate.x < maze->width - 1 && !maze->grid[cellule->coordonate.y][cellule->coordonate.x + 1].visite && !cellule->wallRight) {
        validDirections[count++] = RIGHT;
    }

    if (cellule->coordonate.y < maze->height - 1 && !maze->grid[cellule->coordonate.y + 1][cellule->coordonate.x].visite && !cellule->wallBottom) {
        validDirections[count++] = DOWN;
    }

    if (cellule->coordonate.x > 0
        && !maze->grid[cellule->coordonate.y][cellule->coordonate.x - 1].visite
        && !maze->grid[cellule->coordonate.y][cellule->coordonate.x - 1].wallRight) {
        validDirections[count++] = LEFT;
        }

    if (count > 0) {
        return validDirections[rand() % count];
    }

    cellule->visite = -1;
    return -1;
}


int backTrackingResolver(Maze* maze) {
    Cellule** mastack = malloc(sizeof(Cellule*) * maze->width * maze->height);
    int stacktop = 0;

    Cellule* startCellule = &maze->grid[maze->start.y][maze->start.x];
    mastack[stacktop++] = startCellule;
    startCellule->visite = 2;

    while (stacktop > 0) {
        printMaze(maze);
        printf("\nÉtape %d...\n", stacktop);
        usleep(1000000);

        Cellule* cellule = mastack[stacktop - 1];

        if (cellule->coordonate.x == maze->end.x && cellule->coordonate.y == maze->end.y) {
            free(mastack);
            return 1;
        }

        Direction direction = randDirectionForSolver(cellule, maze);
        printf("direction = %d\n", direction);

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

            if (nextCellule->visite == 0) {
                nextCellule->visite = 2;
                mastack[stacktop++] = nextCellule;
            }
        } else {
            cellule->visite = -1;
            stacktop--;
        }
    }

    free(mastack);
    return 0;
}


int resolve(Maze* maze) {
    printf("\n");
    printf("Resolving...\n");

    if (backTrackingResolver(maze)) {
        printf("Labyrinthe résolu avec succès !\n");
    } else {
        printf("Impossible de résoudre le labyrinthe.\n");
    }


    return 0 ;
}





