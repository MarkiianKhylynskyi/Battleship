cmake_minimum_required(VERSION 3.13 FATAL_ERROR)

set(PROJECT_NAME Battleship)
project(${PROJECT_NAME})

add_executable(${PROJECT_NAME} 
	src/main.cpp
	src/computer.cpp
	src/human.cpp
	src/grid.cpp
	src/player.cpp
)
