#include <iostream>
#include "player.h"

int main() {

    std::string cmd;
    Player* SonyWalkman = new Player ();
    while (cmd != "exit"){
        std::cout << ": ";
        std::cin>>cmd;


        if (cmd == "play"){
            SonyWalkman->play();
        }
        if(cmd == "pause"){
            SonyWalkman->pause();
        }
        if(cmd == "stop"){
            SonyWalkman->stop();
        }
        if(cmd == "next"){
            SonyWalkman->next();
        }
    }
    SonyWalkman -> exit();
    delete SonyWalkman;
    SonyWalkman = nullptr;
}