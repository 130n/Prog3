#include "GameEngine.h"
#include "Protagonist.h"
#include "Antagonist.h"
#include "Treat.h"
#include <string>

namespace Spel{

	Protagonist::Protagonist( int x, int y, std::string img_path):
	Sprite(x, y, 0, 0, img_path, true)
	{
		score = 0;
	}


	void Protagonist::tick(std::vector<Sprite*>)
	{
		//tom
	}
	void Protagonist::handleInput(SDL_Event& e){
		if (e.type == SDL_MOUSEMOTION)
		{
			setX(e.motion.x-getWidth()/2);
			setY(e.motion.y-getHeight()/2);
		}
	}
	bool Protagonist::collisionCheck(std::vector<Sprite*> vsprites)
	{
		// return false;
		extern Motor::GameEngine spel;
		bool collis = false;
		int top = getY();
		int bottom = getY()+getHeight();
		int left = getX();
		int right = getX()+getWidth();
		for (int i = 0; i < vsprites.size(); ++i)
		{
			if (Protagonist* p=dynamic_cast<Protagonist*>(vsprites[i]))
			{
				continue;
			}
			if (Treat* t=dynamic_cast<Treat*>(vsprites[i]))
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
				scorePP();
			}
		}
		return collis;
	}
	void Protagonist::scorePP()
	{
		++score;
	}
	int Protagonist::getScore()
	{
		return score;
	}
}