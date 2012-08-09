#ifndef SPRITE_H
#define SPRITE_H
#include "Image.h"
#include <string>
#include <vector>

namespace Motor
{
	class Sprite
	{
		public:
			void blit(SDL_Surface*) const;
			//virts
			
			virtual void draw(SDL_Surface*) const=0;
			virtual ~Sprite(){}
			virtual void tick(std::vector<Sprite*>)=0;
			virtual void handleInput(SDL_Event& e) = 0;
			virtual void collisionCheck(std::vector<Sprite*>)=0;
			//getters
			const Image& getSpriteBild() const;
			int getX() const;
			int getY() const;
			float getXvel() const;
			float getYvel() const;
			//setters
			void setX(int x);
			void setY(int y);
			void setXvel(float x);
			void setYvel(float y);

		protected:
			Sprite(int x, int y, int sX, int sY, std::string imgpath, bool transp): 
				x(x), 
				y(y), 
				xVel(sX), 
				yVel(sY), 
				sprite_bild(imgpath, transp)
				{
					//TOMT
				}
		private:
			//copy
			Sprite(const Sprite& other):
				sprite_bild(other.getSpriteBild()){}
			//tilldeln
			const Sprite& operator=(const Sprite& other);
			Image sprite_bild;
			//position
			int x;
			int y;
			//rörelse
			float xVel;
			float yVel;
	};
}

#endif
