#include "Sprite.h"
#include "SDL_image.h"

namespace Motor
{
	/*blit tar en surface som argument så den vet
	* var den ska rita
	*/
	void Sprite::blit(SDL_Surface* destination_screen) const
	{

		SDL_Rect offset;

		offset.x = getX();
		offset.y = getY();

		SDL_BlitSurface(getSpriteBild().getBild(), NULL, destination_screen, &offset);
		///här pajjar det
		std::cout << "blit4" <<std::endl;

	}
	//tilldeln
	const Sprite& Sprite::operator=(const Sprite& other)
	{
		if(this != &other)
		{
			sprite_bild = other.getSpriteBild();
		}
		return *this;
	}
	/*
	* getters
	*/
	const Image& Sprite::getSpriteBild() const
	{
		return sprite_bild;
	}
	int Sprite::getX() const 
	{
		return x;
	}
	int Sprite::getY() const
	{
		return y;
	}
	float Sprite::getXvel() const
	{
		return xVel;
	}
	float Sprite::getYvel() const
	{
		return yVel;
	}
	/*
	* setters
	*/
	void Sprite::setX(int x)
	{
		this->x = x;
	}
	void Sprite::setY(int y)
	{
		this->y = y;
	}
	void Sprite::setXvel(float x)
	{
		this->xVel = x;
	}
	void Sprite::setYvel(float y)
	{
		this->yVel = y;
	}

}