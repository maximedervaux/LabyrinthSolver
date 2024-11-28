//
// Created by Maxime Dervaux on 25/11/2024.
//

#ifndef RESOLVER_H
#define RESOLVER_H


#include "maze.h"

int resolve(Maze* maze);
void startBacktracking(Maze* maze);
int stepBacktracking(Maze* maze);

#endif //RESOLVER_H
