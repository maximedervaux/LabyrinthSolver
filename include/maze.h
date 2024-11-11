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
    int width;
    int height;
    Coordinates start;
    Coordinates end;
    int **grid;
} Maze;


Maze* createMaze(int width, int height);
void printMaze(Maze* maze);
void freeMaze(Maze* maze);





#endif //MAZE_H
