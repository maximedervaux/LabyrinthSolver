cmake_minimum_required(VERSION 3.29)
project(LabyrinthSolver C)

# Spécifiez la version du standard C
set(CMAKE_C_STANDARD 11)

# Ajouter les fichiers source
add_executable(LabyrinthSolver
        src/main.c
        include/maze.h
        src/maze.c
        src/resolver.c
        include/resolver.h
        src/raylib.c
        include/raylib.h
        include/config.h
)

find_package(raylib REQUIRED)

if (raylib_FOUND)
    include_directories(${raylib_INCLUDE_DIRS})
    target_link_libraries(LabyrinthSolver ${raylib_LIBRARIES})
else()
    message(FATAL_ERROR "Raylib n'a pas été trouvé.")
endif()