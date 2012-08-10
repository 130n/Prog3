#include "Image.h"
#include "GameEngine.h"
#include "Avatar.h"
#include <iostream>

Motor::GameEngine spel;// = GameEngine(60,100,100);

int main(int argc, char* args[]){
    // Motor::Sprite* player = new Spel::Avatar(100,100);
    Spel::Avatar* player = new Spel::Avatar(100,100);
    Spel::Avatar* player2 = new Spel::Avatar(200,100);

    spel.add(player);
    spel.eventloop();
    return 0;
}