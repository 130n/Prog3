#include "GameEngine.h"
#include "Protagonist.h"
#include "Antagonist.h"
#include "Treat.h"
namespace Motor
{

	GameEngine::GameEngine(
		int fps, 
		int width, 
		int height
		): FPS(fps), WIDTH(width), HEIGHT(height)
	{

		std::cout<<"======================"<<std::endl;
		std::cout<<"========START========="<<std::endl;

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
  	/*
  	* GETTERS
	*/
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

    /*
    * Destruktor
    * innehåller lite icke-generell kod med resultat
    */
	GameEngine::~GameEngine()
	{
		int enemies = vsprites.size()-2;
		for(unsigned int i=0; i<vsprites.size(); ++i)
		{
			delete vsprites[i];
		}
		delete screen;

	    std::cout<<"Antal Antagonister: "<<enemies<<std::endl;
		std::cout<<"======GAME OVER======="<<std::endl;
		std::cout<<"======================"<<std::endl;

		SDL_Quit();
	}

	void GameEngine::addAction(Func action)
	{
		if (action==NULL)
		{
			return;
		}
		else
		{
			vactions.push_back(action);
		}
	}
	/*
	* eventloop
	*/
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
			}
			/*
			* tickloop
			*/
			for (unsigned int i = 0; i < vsprites.size(); ++i)
			{
				vsprites[i]->tick(vsprites);
			}
			/*
			* kollisionsloop
			*/
			for (unsigned int i = 0; i < vsprites.size(); ++i)
			{
				if(vsprites[i]->collisionCheck(vsprites))
				{
					SDL_Delay(1000); //pausar så man hinner se vad som hände i dödsögonblicket
					running=false; //stoppar main loopen
				}
			}//kollisionsloop

			if (!vactions.empty())
			{
				for (int i = 0; i < vactions.size(); ++i)
				{
					vactions[i]();
				}
			}

			/*
			* blitloop
			*/
			Uint32 screenBG = SDL_MapRGB(getScreen()->format,0,0,0);
			SDL_FillRect(getScreen(),NULL,screenBG);
			//blittar alla sprites
			for (unsigned int i = 0; i < vsprites.size(); ++i)
			{
				vsprites[i]->blit(getScreen());
			}

			SDL_Flip(getScreen());

			/*
			* delay
			*/
			time_delay = time_left - SDL_GetTicks();

			if( 0 < time_delay)
			{
				SDL_Delay(time_delay);
			}
		}//while
	}//eventloop()
}//namespace Motor
