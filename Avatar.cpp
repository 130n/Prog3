#include "GameEngine.h"
#include "Avatar.h"
#include <string>

namespace Spel{

	Avatar::Avatar(std::string img_path, int x, int y):
	Sprite(x, y, 0, 0, img_path, true)
	{
		lives = 3;
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