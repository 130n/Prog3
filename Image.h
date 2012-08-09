#ifndef IMAGE_H
#define IMAGE_H
#include <string>
#include "SDL.h"
#include "SDL_image.h"
#include <iostream>

namespace Motor{
    class Image
    {
        public:
            Image(); //default konstruktor
            Image(const Image& img); //copy konstruktor
            Image(std::string filename, bool transparent); //konstruktor
            const Image& operator=(const Image& other); //placeholder
            ~Image(); //destruktor
            SDL_Surface* getBild() const;
            void testPrintRefcount(); //Printa refcount
        private:
            SDL_Surface* bild;
    };
}
#endif // IMAGE_H
