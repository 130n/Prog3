#ifndef AVATAR_H
#define AVATAR_H

#include "Sprite.h"
#include <string>
#include <vector>

namespace Spel
{

	class Avatar : public Motor::Sprite
	{
		public:
			Avatar(std::string img_path, int x, int y);
			// ~Avatar(){
			// 	// delete getSpriteBild();
			// };
			void tick(std::vector<Sprite*>);
			void handleInput(SDL_Event&);
			void collisionCheck(std::vector<Sprite*>);
		private:
			int lives;
	};
}

#endif