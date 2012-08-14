#ifndef BOMB_H
#define BOMB_H

namespace Spel
{
	class Bomb : public Spel::Antagonist
	{
		public:
			Bomb(int x, int y, std::string img="bomb.png");			
			void tick(std::vector<Sprite*>);
			void handleInput(SDL_Event& e);
			void collisionCheck(std::vector<Sprite*>);
		private:
			int fuse;
	}
};
#endif