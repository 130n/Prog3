#include "GameEngine.h"
#include "Avatar.h"
#include <string>

namespace Spel{

	Avatar::Avatar( int x, int y, std::string img_path):
	Sprite(x, y, 0, 0, img_path, true)
	{
		lives = 3;
	}
	void Avatar::draw(SDL_Surface* screen) const
	{
		SDL_Rect tmp;
		tmp.x = getX();
		tmp.y = getY();
		SDL_BlitSurface(getSpriteBild().getBild(), NULL, screen, &tmp);
	}

	void Avatar::tick(std::vector<Sprite*>)
	{

	}
	void Avatar::handleInput(SDL_Event&){

	}
	void Avatar::collisionCheck(std::vector<Sprite*>)
	{

	}
}