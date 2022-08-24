#include "player.h"
#include <limits>

void Player::play (){
    if (!playingSong) {
        playingSong = true;
        std::cout << "Enter band and song name: ";
        std::string nameOfSong;
        {std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            getline(std::cin, nameOfSong);}
        if (nameOfSong == firstTrk->getNameTrack()) {
            playing(firstTrk);
        } else if (nameOfSong == secondTrk->getNameTrack()) {
            playing(secondTrk);
        } else if (nameOfSong == thirdTrk->getNameTrack()) {
            playing(thirdTrk);
        }else if (nameOfSong == fourthTrk->getNameTrack()){
            playing (fourthTrk);
        } else {std::cout << "This track is not found";}

    } else  if (pauseSong) {pauseSong = false;} // снимаем с паузы

};
void Player::pause (){
    if(playingSong && !pauseSong) {
        pauseSong = true;
        std::cout << "The song is paused\n";
    }
}

void Player::next () {
    std::srand(std::time(nullptr));
    int nextSong = std::rand()%5 +1;

    switch (nextSong){
        case 1 :playing(firstTrk);
        case 2 :playing(secondTrk);
        case 3 :playing(thirdTrk);
        case 4 :playing (fourthTrk);
        default:playing(firstTrk);
    }
}
void Player::stop(){
    if (playingSong){
        playingSong = false;
        pauseSong = false;
        std::cout << "Playback stopped";
    }
}
void Player::exit (){
delete firstTrk; firstTrk = nullptr;
delete secondTrk; secondTrk = nullptr;
delete thirdTrk; thirdTrk = nullptr;
delete fourthTrk; fourthTrk = nullptr;
}