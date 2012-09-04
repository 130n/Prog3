#include "Image.h"
#include "GameEngine.h"
#include "Protagonist.h"
#include "Antagonist.h"
#include "Treat.h"
#include <iostream>


Motor::GameEngine spel;

void spawn()
{
    //blir slumpmässigt men med högsannolikhet att de spawnar med några sekunders mellanrum
    if (SDL_GetTicks()%1000==0)
    {
        spel.add(new Spel::Antagonist(
            (rand()%(SCREEN_WIDTH - 64)), 
                (rand()%(SCREEN_HEIGHT - 64)) ));
    }
}

int main(int argc, char* args[]){
    Motor::Sprite* player = new Spel::Protagonist(SCREEN_HEIGHT/2,SCREEN_WIDTH/2);
    Motor::Sprite* enemy1 = new Spel::Antagonist(0,0);
    Motor::Sprite* enemy2 = new Spel::Antagonist(SCREEN_WIDTH-64,0);
    Motor::Sprite* enemy3 = new Spel::Antagonist(0,SCREEN_HEIGHT-64);
    Motor::Sprite* enemy4 = new Spel::Antagonist(SCREEN_WIDTH-64,SCREEN_HEIGHT-64);
    Motor::Sprite* apple = new Spel::Treat(100,150);


    spel.add(player);
    spel.add(enemy1);    
    spel.add(enemy2);    
    spel.add(enemy3);    
    spel.add(enemy4);
    spel.add(apple);

    spel.addAction(&spawn);
    SDL_WM_SetCaption( "Kim Jong-ils Matjakt", NULL );
    spel.eventloop();
    // delete spel;
    return 0;
}