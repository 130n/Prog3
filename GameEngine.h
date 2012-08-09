#ifndef GAMEENGINE_H
#define GAMEENGINE_H
#include "SDL.h"
#include "Sprite.h"
#include <iostream>
#include <string>
#include <vector>
namespace Motor
{
    class GameEngine
    {
	    public:
	        GameEngine
	        (
	        	int fps = 60, 
	        	int width = 640, 
	        	int height = 480
	        ); 
	        ~GameEngine();
	        void eventloop();
	        void add(Motor::Sprite*);
	        SDL_Surface* getScreen() const;
	    private:
	    	//extern?
	    	SDL_Surface* screen;
	    	bool running;
	        const int FPS;
	        const int WIDTH;
	        const int HEIGHT;
	        std::vector<Sprite*> vsprites;
    };

}
#endif
