#include "GameEngine.h"
#include "Protagonist.h"
#include <string>

namespace Spel{

	Protagonist::Protagonist( int x, int y, std::string img_path):
	Sprite(x, y, 0, 0, img_path, true)
	{
		lives = 3;
	}

	void Protagonist::tick(std::vector<Sprite*>)
	{

	}
	void Protagonist::handleInput(SDL_Event& e){
		if (e.type == SDL_MOUSEMOTION)
		{
			setX(e.motion.x-getWidth()/2);
			setY(e.motion.y-getHeight()/2);
		}
	}
	void Protagonist::collisionCheck(std::vector<Sprite*>)
	{

	}
}