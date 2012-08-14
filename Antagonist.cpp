#include "Antagonist.h"
#include "GameEngine.h"


namespace Spel
{

	Antagonist::Antagonist(int x, int y, std::string img): Sprite(x, y, 1, 1, img, true)
	{
		//
	}
	void Antagonist::blit() const
	{

	}
	void Antagonist::tick(std::vector<Sprite*> vsprites)
	{
		if (getX()<0 || (getX()+getWidth()) >= SCREEN_WIDTH)
		{
			std::cout << getWidth() <<" "<<getX()<< std::endl;
			setXvel(-getXvel());
		}

		if (getY()<0 || ((getY()+getHeight()) >= SCREEN_HEIGHT))
		{
			std::cout << getHeight() <<" "<<getY()<< std::endl;
			setYvel(-getYvel());
		}
			setX(getX()+getXvel());
			setY(getY()+getYvel());
	}
	void Antagonist::handleInput(SDL_Event& e)
	{

	}
	//kanske
	void Antagonist::collisionCheck(std::vector<Sprite*> vsprites)
	{

	}
}