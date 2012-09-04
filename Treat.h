#ifndef TREAT_H
#define TREAT_H
#include "Sprite.h"

namespace Spel
{
	class Treat : public Motor::Sprite
	{
		public:
			Treat(int x, int y, std::string img="apple-icon.png"):Sprite(x, y, 0, 0, img, true),fuse(180){}			
			void tick(std::vector<Sprite*>);
			void handleInput(SDL_Event& e);
			bool collisionCheck(std::vector<Sprite*>);
			void teleport();
		private:
			int fuse;
	};
}
#endif