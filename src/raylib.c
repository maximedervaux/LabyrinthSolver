#include "raylib.h"

#include <stdlib.h>

#include "../include/maze.h"
#include "../include/config.h"

// Initialisation de Raylib
void initGraphics(int screenWidth, int screenHeight) {
    InitWindow(screenWidth, screenHeight, "Labyrinth Generator/Solver");
    SetTargetFPS(60);
}

void drawMaze(Maze *maze) {
    const int OFFSET_X = 350;
    const int OFFSET_Y = 50;

    int maxDistance = (maze->width * maze->height)/10;

    for (int y = 0; y < maze->height; y++) {
        for (int x = 0; x < maze->width; x++) {
            Cellule cell = maze->grid[y][x];

            int screenX = OFFSET_X + x * CELL_SIZE;
            int screenY = OFFSET_Y +y * CELL_SIZE ;

            // Dégradé basé sur la distance de Manhattan par rapport au point de départ J'ai galéré 🥲(merci gpt)
            if (cell.visite == 2) {

                int distance = abs(maze->start.x - x) + abs(maze->start.y - y);

                float percentage = (float)distance / (maxDistance / 3.0f);

                if (percentage > 1.0f) percentage = 1.0f;

                int red = (int)(percentage * 255);
                int green = (int)((1.0f - percentage) * 255);
                int blue = (int)((percentage / 3) * 255);

                Color gradientColor = (Color){red, green, blue, 255};

                DrawRectangle(screenX, screenY, CELL_SIZE, CELL_SIZE, gradientColor);
            }

            // Murs
            if (cell.wallRight) {
                DrawLine(screenX + CELL_SIZE, screenY, screenX + CELL_SIZE, screenY + CELL_SIZE, PRIMARY_COLOR);
            }
            if (cell.wallBottom) {
                DrawLine(screenX, screenY + CELL_SIZE, screenX + CELL_SIZE, screenY + CELL_SIZE, PRIMARY_COLOR);
            }
        }
    }

    DrawRectangleLines(OFFSET_X, OFFSET_Y, maze->width * CELL_SIZE, maze->height * CELL_SIZE, PRIMARY_COLOR);

    DrawCircle(OFFSET_X + maze->start.x * CELL_SIZE + CELL_SIZE / 2, OFFSET_Y+ maze->start.y * CELL_SIZE + CELL_SIZE / 2, CELL_SIZE / 4, BLUE);
    DrawCircle(OFFSET_X + maze->end.x * CELL_SIZE + CELL_SIZE / 2, OFFSET_Y+ maze->end.y * CELL_SIZE + CELL_SIZE / 2, CELL_SIZE / 4, RED);
}

