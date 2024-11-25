//
// Created by Maxime Dervaux on 11/11/2024.
//

#ifndef MAZE_H
#define MAZE_H

typedef struct {
    int x;
    int y;
}Coordinates;

typedef struct {
    int visite;            // 0 = non visité, 1 = visité, 2 = fait partie du resultat , -1 = Cul de sac
    int wallBottom;
    int wallRight;
    Coordinates coordonate;
}Cellule;

typedef struct {
    int width;
    int height;
    Coordinates start;
    Coordinates end;
    Cellule **grid;
} Maze;

typedef enum {
    UP = 0,
    RIGHT = 1,
    DOWN = 2,
    LEFT = 3
} Direction;


Maze* createMaze(int width, int height);
void printMaze(Maze* maze);
void freeMaze(Maze* maze);
int backTrackingGenerator(Maze* maze, Cellule* cellule);
void resetVisite(Maze* maze);





#endif //MAZE_H
