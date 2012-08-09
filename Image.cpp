#include "Image.h"
#include <stdexcept>

// using namespace std;
namespace Motor
{
    Image::Image()
    {
        //tom
    }
    void Image::testPrintRefcount()
    {
        std::cout << "num refs: " << bild->refcount << std::endl;
    }
    //konstruktor
    Image::Image(std::string filename, bool transparent)
    {
        SDL_Surface* laddadBild = NULL;
        SDL_Surface* format = NULL;

        laddadBild = IMG_Load(filename.c_str());

        if (laddadBild != NULL)
        {
            //SDL_Init måste vara laddad innan detta
            format =SDL_DisplayFormat(laddadBild);
        
            SDL_FreeSurface(laddadBild);

            if(transparent)
            {
                Uint32 transpBG = *(Uint32*)format->pixels;
                SDL_SetColorKey(format, SDL_SRCCOLORKEY | SDL_RLEACCEL, transpBG);
            }

            bild = format;
        }
        else
        {
            throw std::out_of_range("Fil saknas"+filename);
        }

    }
    //copy
    Image::Image(const Image& img)
    {
        bild =img.bild;
        bild->refcount++;
    }
    SDL_Surface* Image::getBild() const
    {
                std::cout << "getBild" <<std::endl;

        return bild;
    }
    //tilldelning
    const Image& Image::operator=(const Image& other)
    {
        if(bild != other.bild){
            if(bild){
                SDL_FreeSurface(bild);
            }
            bild = other.getBild();
            bild->refcount++;
        }
        return *this;
    }
    //destruktor
    Image::~Image()
    {
        std::cout<<bild->refcount<<"d"<<std::endl;
        if(bild)
        {
            SDL_FreeSurface(bild);
        }
    }

}