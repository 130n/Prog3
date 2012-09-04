#ifndef PROTAGONIST_H
#define PROTAGONIST_H

#include "Sprite.h"
#include "Constants.h"
#include <string>
#include <vector>

namespace Spel
{

	class Protagonist : public Motor::Sprite
	{
		public:
			Protagonist(int x, int y, std::string img_path="smiley.bmp");
			~Protagonist()
			{
				std::cout << "      SCORE: " << score << std::endl;
			}
			void tick(std::vector<Sprite*>);
			void handleInput(SDL_Event&);
			bool collisionCheck(std::vector<Sprite*>);
			int getScore();
			void scorePP();
		private:
			int score;
	};
}

#endif