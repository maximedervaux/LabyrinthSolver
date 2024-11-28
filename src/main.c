#include "raylib.h"
#include "../include/maze.h"
#include "../include/resolver.h"
#include "../include/raylib.h"

#include "../include/config.h"

int main(void) {
    // Initialisation Raylib
    InitWindow(SCREEN_WIDTH, SCREEN_HEIGHT, "Maze Solver");
    SetTargetFPS(60);

    // Création du labyrinthe
    Maze* monlabyrinthe = createMaze(MAZE_WIDTH, MAZE_HEIGHT);
    backTrackingGenerator(monlabyrinthe, &monlabyrinthe->grid[monlabyrinthe->start.y][monlabyrinthe->start.x]);
    startBacktracking(monlabyrinthe);

    int resolutionDone = 0;

    while (!WindowShouldClose()) {

        if (IsKeyPressed(KEY_R)) {
            freeMaze(monlabyrinthe);
            monlabyrinthe = createMaze(MAZE_WIDTH, MAZE_HEIGHT);
            backTrackingGenerator(monlabyrinthe, &monlabyrinthe->grid[monlabyrinthe->start.y][monlabyrinthe->start.x]);
            startBacktracking(monlabyrinthe);
            resolutionDone = 0;
        }

        if (!resolutionDone) {
            resolutionDone = stepBacktracking(monlabyrinthe);
        }

        BeginDrawing();
        ClearBackground(BACKGROUND_COLOR);

        drawMaze(monlabyrinthe);

        DrawText("[ESC] EXIT  [R] REGENERATE", 10, 10, 20, GREEN);
        if (resolutionDone) {
            DrawText("Labyrinthe résolu !", (SCREEN_WIDTH/5), SCREEN_HEIGHT/3, 50, GREEN);
        } else {
            DrawText("Résolution en cours...", 10, 50, 20, DARKGRAY);
        }

        EndDrawing();
    }

    freeMaze(monlabyrinthe);
    CloseWindow();

    return 0;
}