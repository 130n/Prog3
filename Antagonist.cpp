#include "Antagonist.h"
#include "Protagonist.h"
#include "GameEngine.h"


namespace Spel
{

	Antagonist::Antagonist(int x, int y, std::string img): Sprite(x, y, 0, 0, img, true)
	{
		summoningSickness = 60;
	}

	void Antagonist::tick(std::vector<Sprite*> vsprites)
	{
		--summoningSickness;
		if (summoningSickness == 0)
		{
			setXvel(2);
			setYvel(2);
		}
		//ändra riktning
		if (getX()<0 || (getX()+getWidth()) >= SCREEN_WIDTH)
		{
			setXvel(-getXvel());
		}

		if (getY()<0 || ((getY()+getHeight()) >= SCREEN_HEIGHT))
		{
			setYvel(-getYvel());
		}
		//flytta
		setX(getX()+getXvel());
		setY(getY()+getYvel());
	}
	void Antagonist::handleInput(SDL_Event& e)
	{
		//tom
	}

	bool Antagonist::collisionCheck(std::vector<Sprite*> vsprites)
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
					* ANNARS ÄR ÖVERLAPPAR DE
					*/
				return true;
			}
			else
			{
				return false;
			}
		}
	}
}