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
    int visite;
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


Maze* createMaze(int width, int height);
void printMaze(Maze* maze);
void freeMaze(Maze* maze);
int backTracking(Maze* maze, Cellule* cellule);





#endif //MAZE_H
