#include "Image.h"
#include "GameEngine.h"
#include "Avatar.h"
#include <iostream>
// using namespace Motor;

Motor::GameEngine spel;// = GameEngine(60,100,100);

int main(int argc, char* args[]){
    // Motor::Sprite* player = new Spel::Avatar(100,100);
    Spel::Avatar* player = new Spel::Avatar(100,100);

    std::cout << "main 1" <<std::endl;

    // player->blit(spel.getScreen());
    std::cout << "main 2 " <<std::endl;
    spel.add(player);
    spel.eventloop();
    return 0;
}