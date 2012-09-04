# 
# Make fil för prog3 spelet med sdl flaggor
# Kör även filen för bekvämlighetens skull
#
# Compiler: g++
#

all: 
	g++ `sdl-config --cflags --libs` Image.cpp Sprite.cpp GameEngine.cpp Protagonist.cpp Antagonist.cpp Treat.cpp main.cpp -lSDL -lSDL_image -o kimjongmat
	./kimjongmat
