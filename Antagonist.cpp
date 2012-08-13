#include "Antagonist.h"

namespace Spel
{

	Antagonist::Antagonist(int x, int y, std::string img): Sprite(x, y, 1, 1, img, true)
	{
		//
	}
	void Antagonist::blit() const
	{

	}
	void Antagonist::tick(std::vector<Sprite*> vsprites){
		setX(getX()+getXvel());
		setY(getY()+getXvel());
	}
	void Antagonist::handleInput(SDL_Event& e)
	{

	}
	//kanske
	void Antagonist::collisionCheck(std::vector<Sprite*> vsprites)
	{

	}
}