cmake_minimum_required(VERSION 3.13 FATAL_ERROR)

set(PROJECT_NAME Battleship)
project(${PROJECT_NAME})

add_executable(${PROJECT_NAME} 
	src/main.cpp
	src/main.h
	src/computer.cpp
	src/computer.h
	src/game.cpp
	src/game.h
	src/human.cpp
	src/human.h
	src/grid.cpp
	src/grid.h
	src/player.cpp
	src/player.h
)
