# 
# Make fil för prog3 spelet med sdl flaggor
#
# Compiler: g++
#

all: 
	g++ `sdl-config --cflags --libs` Image.cpp Sprite.cpp GameEngine.cpp Avatar.cpp main.cpp -lSDL -lSDL_image -o thegame
	./thegame