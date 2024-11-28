#ifndef RAYLIB_GRAPHICS_H
#define RAYLIB_GRAPHICS_H

#include "../include/maze.h"
#include "config.h"


void initGraphics(int screenWidth, int screenHeight);
void drawMaze(Maze *maze);

#endif