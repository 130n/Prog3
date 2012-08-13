#include "Image.h"
#include "GameEngine.h"
#include "Protagonist.h"
#include "Antagonist.h"
#include <iostream>

Motor::GameEngine spel;// = GameEngine(60,100,100);

int main(int argc, char* args[]){
    // Motor::Sprite* player = new Spel::Protagonist(100,100);
    Motor::Sprite* player = new Spel::Protagonist(100,100);
    Motor::Sprite* enemy2 = new Spel::Antagonist(0,50);
    Motor::Sprite* enemy1 = new Spel::Antagonist(0,0);

    spel.add(enemy2);
    spel.add(player);
    spel.add(enemy1);    

    spel.eventloop();
    return 0;
}