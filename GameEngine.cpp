#include "GameEngine.h"
namespace Motor
{

	GameEngine::GameEngine(
		int fps, 
		int width, 
		int height
		): FPS(fps), WIDTH(width), HEIGHT(height)
	{
		if(SDL_Init(SDL_INIT_EVERYTHING) != -1)
		{
			screen = SDL_SetVideoMode(WIDTH,HEIGHT,32, 
				SDL_SWSURFACE || SDL_DOUBLEBUF);
			running= true;

			//för test
			SDL_Delay(1000);
		}
	}

	// SDL_Surface* GameEngine::getScreen() const
	// {
	// 	return screen;
	// }

	GameEngine::~GameEngine()
	{
		for(int i=0; i<vsprites.size(); i++)
		{
			delete vsprites[i];
		}
		SDL_Quit();
	}

	void GameEngine::eventloop()
	{
		int time_delay;
		SDL_Event event;
		while(running)
		{
			while(SDL_PollEvent(&event))
			{
				if(event.type == SDL_QUIT)
				{
					running = false;
				}
				if(event.type==SDL_KEYDOWN)
				{
					switch(event.key.keysym.sym)
					{
						case SDLK_ESCAPE:
							running = false;
							break;
						case SDLK_q:
							running = false;
							break;
						case SDLK_UP:
							//something
							break;
						case SDLK_DOWN:
							//something else
							break;
						case SDLK_LEFT:
							//something
							break;
						case SDLK_RIGHT:
							//something else
							break;
						case SDLK_SPACE:
							//skjut?
							break;
					}
				}
				if(event.type == SDL_MOUSEMOTION)
				{

				}
			}

			//filler
			if(time_delay)
				SDL_Delay(time_delay);
		}

	}
}
