#include "Bomb.h"
namespace Spel{
	void Bomb::tick(std::vector<Sprite*> vsprites)
	{
		--fuse;
		if(fuse<=0)
		{
			~Bomb();
		}
	}
	void handleInput(SDL_Event& e)
	{

	}
}