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


    int GameEngine::getWidth()
    {
    	return WIDTH;
    }

    int GameEngine::getHeight()
    {
    	return HEIGHT;
    }

	GameEngine::~GameEngine()
	{
		for(unsigned int i=0; i<vsprites.size(); ++i)
		{
			delete vsprites[i];
		}
		SDL_Quit();
	}

	void GameEngine::eventloop()
	{
		int time_delay;
		int TIMEFRAME = 1000/FPS;
		SDL_Event event;
		Uint32 time_left;
		while(running)
		{
			//startar 
			time_left=SDL_GetTicks()+TIMEFRAME;

			while(SDL_PollEvent(&event))
			{
				if(event.type == SDL_QUIT)
				{
					running = false;
				}
				else if(event.type==SDL_KEYDOWN)
				{
					switch(event.key.keysym.sym)
					{
						case SDLK_ESCAPE:
							running = false;
							break;
						case SDLK_q:
							running = false;
							break;
					}
				}
				for (unsigned int i = 0; i < vsprites.size(); ++i)
				{
					vsprites[i]->handleInput(event);
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
				vsprites[i]->tick(vsprites);
			}

			Uint32 screenBG = SDL_MapRGB(getScreen()->format,0,0,0);
			SDL_FillRect(getScreen(),NULL,screenBG);

			/*
			* blitloop
			*/
			for (unsigned int i = 0; i < vsprites.size(); ++i)
			{
				vsprites[i]->blit(getScreen());
				// vsprites[i]->draw(getScreen());
			}

			SDL_Flip(getScreen());

			//delay
			time_delay = time_left - SDL_GetTicks();
			std::cout<<SDL_GetTicks()<<std::endl;
			if( 0 < time_delay)
			{
				SDL_Delay(time_delay);
			}
		}

	}
}
