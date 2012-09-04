#ifndef GAMEENGINE_H
#define GAMEENGINE_H
#include "SDL.h"
#include "Sprite.h"
#include "Constants.h"
#include <iostream>
#include <string>
#include <vector>
namespace Motor
{
    class GameEngine
    {
    	//funktionspekare
    	typedef void (*Func)();
	    
	    public:
	        GameEngine
	        (
	        	int fps = FRAMES_PER_SECOND, 
	        	int width = SCREEN_WIDTH, 
	        	int height = SCREEN_HEIGHT
	        ); 
	        ~GameEngine();

	        void addAction(Func action); 
	        void eventloop();
	        void add(Motor::Sprite*);
	        SDL_Surface* getScreen() const;
	        int getWidth();
	        int getHeight();
	    private:
	    	//vector med funktioner tillagda med addAction
	        std::vector<Func> vactions;
	        //vector med sprites
	        std::vector<Sprite*> vsprites;
	        //fönstret
	    	SDL_Surface* screen;
	    	bool running;
	        const int FPS;
	        const int WIDTH;
	        const int HEIGHT;
    };

}
#endif
