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
		}
	}

	void GameEngine::add(Sprite* s)
	{
		vsprites.push_back(s);
	}

	SDL_Surface* GameEngine::getScreen() const
	{
		return screen;
	}

	GameEngine::~GameEngine()
	{
		for(unsigned int i=0; i<vsprites.size(); i++)
		{
			delete vsprites[i];
		}
		SDL_Quit();
	}

	void GameEngine::eventloop()
	{
	    std::cout << "start" <<std::endl;

		int time_delay;
		SDL_Event event;
		while(running)
		{
		    std::cout << "mainloop" <<std::endl;

			while(SDL_PollEvent(&event))
			{
				std::cout << "eventloop" <<std::endl;
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
			/*
			* tickloop
			*/
			for (unsigned int i = 0; i < vsprites.size(); ++i)
			{
				std::cout << "tick" <<std::endl;
				vsprites[i]->tick(vsprites);
			}

			Uint32 screenBG = SDL_MapRGB(getScreen()->format,0,0,0);
			SDL_FillRect(getScreen(),NULL,screenBG);

			/*
			* blitloop
			*/
			for (unsigned int i = 0; i < vsprites.size(); ++i)
			{
				std::cout << "blit" <<std::endl;
				vsprites[i]->blit(getScreen());
				// vsprites[i]->draw(getScreen());
			}

			SDL_Flip(getScreen());

			//filler
			// if(time_delay)
			// 	SDL_Delay(time_delay);
		}

	}
}
