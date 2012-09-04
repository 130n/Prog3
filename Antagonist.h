#ifndef ANTAGONIST_H
#define ANTAGONIST_H

#include "GameEngine.h"
#include "Constants.h"
#include "Sprite.h"
#include <string>

namespace Spel
{
	class Antagonist : public Motor::Sprite
	{
		public:	
			Antagonist(int x, int y, std::string img="kim.jpg");
			void blit() const;
			void tick(std::vector<Sprite*>);
			void handleInput(SDL_Event&);
		//kanske
			bool collisionCheck(std::vector<Sprite*>);
		private:
			int summoningSickness;
	};
}

#endif