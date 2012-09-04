#include "Treat.h"
#include "Protagonist.h"
namespace Spel{
	void Treat::tick(std::vector<Sprite*> vsprites)
	{
		--fuse;
		if(fuse<=0)
		{
			fuse=180;
			teleport();
		}
	}
	void Treat::teleport()
	{
		fuse = 180;
		int new_x = rand()%(SCREEN_WIDTH - getWidth());
			int new_y = rand()%(SCREEN_HEIGHT - getHeight());
			setX(new_x);
			setY(new_y);	
	}
	void Treat::handleInput(SDL_Event& e)
	{

	}
	bool Treat::collisionCheck(std::vector<Sprite*> vsprites)
	{
		int top = getY();
		int bottom = getY()+getHeight();
		int left = getX();
		int right = getX()+getWidth();
		for (unsigned int i = 0; i < vsprites.size(); ++i)
		{
			if (Protagonist* p=dynamic_cast<Protagonist*>(vsprites[i]))
			{
				int other_top = vsprites[i]->getY();
				int other_bottom = vsprites[i]->getY()+vsprites[i]->getHeight();
				int other_left = vsprites[i]->getX();
				int other_right = vsprites[i]->getX()+vsprites[i]->getWidth();
				//other är ovanför
				if (other_bottom<top)
				{
					continue;
				}
				//other är under
				if (other_top>bottom)
				{
					continue;
				}
				//till vänster
				if (other_right<left)
				{
					continue;
				}
				//till höger
				if (other_left>right)
				{
					continue;
				}
					/*
					* flytta äpplet
					*/
					teleport();
					/*
					returnerar false då allt som ska göras görs här
					undviker att stoppa spelet i game engine
					*/
				return false;
			}
			else
			{
				return false;
			}
		}
	}
}