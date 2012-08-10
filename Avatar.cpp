#include "GameEngine.h"
#include "Avatar.h"
#include <string>

namespace Spel{

	Avatar::Avatar( int x, int y, std::string img_path):
	Sprite(x, y, 0, 0, img_path, true)
	{
		lives = 3;
		width = getSpriteBild().getBild()->w;
		height = getSpriteBild().getBild()->h;
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
	void Avatar::handleInput(SDL_Event& e){
		if (e.type == SDL_MOUSEMOTION)
		{
			setX(e.motion.x-width/2);
			setY(e.motion.y-height/2);
		}
	}
	void Avatar::collisionCheck(std::vector<Sprite*>)
	{

	}
}