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
			Avatar(int x, int y, std::string img_path="smiley1.png");
			// ~Avatar(){
			// 	// delete getSpriteBild();
			// };
			void draw(SDL_Surface*) const;

			void tick(std::vector<Sprite*>);
			void handleInput(SDL_Event&);
			void collisionCheck(std::vector<Sprite*>);
		private:
			int lives;
	};
}

#endif