cmake_minimum_required(VERSION 3.29)
project(LabyrinthSolver C)

set(CMAKE_C_STANDARD 11)

add_executable(LabyrinthSolver main.c
        include/maze.h
        maze.c
)
