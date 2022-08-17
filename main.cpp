#include <iostream>
#include <ctime>
#include <cstdlib>



class Track {

    std::string nameTrack = "";
    std::tm dateOfCreation;
    time_t duration = 180;

public:

    Track (std::string name, int yearOfCreat,int monthOfCreat,time_t d){
        nameTrack = name;
        dateOfCreation.tm_year = yearOfCreat;
        dateOfCreation.tm_mon = monthOfCreat;
        duration = d;
    }
    std::string getNameTrack (){
        return nameTrack;
    }
    std::tm getDateOfCreation(){
        return dateOfCreation;
    }
    time_t getDuration () {
        return duration;
    }
};

class Player {
    Track* firstTrk = new Track ("Sting - Shape of my heart",1993,9,281);
    Track* secondTrk = new Track ("Deep purple - Smoke on the water",1971,06,343);
    Track* thirdTrk = new Track ( "Queen - Bohemian Rhapsody",1975,11,355);
    Track* fourthTrk = new Track ("Beatles - Yesterday",1965,9,123);

    bool playingSong = false;
    bool pauseSong = false;
   static void playing (Track* Trk){
        std::cout << "Now playing: " << Trk->getNameTrack () << " || " << Trk->getDateOfCreation().tm_year
                  << "/" << Trk->getDateOfCreation().tm_mon << " || " << Trk->getDuration () /60 << "min "
                  << Trk->getDuration () %60 << "sec\n";
    }

public:

    void play (){
       if (!playingSong) {
           playingSong = true;
           std::cout << "Enter band and song name: ";
           std::string nameOfSong;
           getline(std::cin, nameOfSong);
           if (nameOfSong == firstTrk->getNameTrack()) {
               playing(firstTrk);
           } else if (nameOfSong == secondTrk->getNameTrack()) {
               playing(secondTrk);
           } else if (nameOfSong == thirdTrk->getNameTrack()) {
               playing(thirdTrk);
           }else if (nameOfSong == fourthTrk->getNameTrack()){
               playing (fourthTrk);
           } else {std::cout << "This track is not found";}

       }
    };

   void pause (){
       if(playingSong && !pauseSong) {
           pauseSong = true;
           std::cout << "The song is paused\n";
       }
   }

   void next () {
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
   void stop(){
       if (playingSong){
           playingSong = false;
           pauseSong = false;
           std::cout << "Playback stopped";
       }
   }
    void exit (){
        delete firstTrk; firstTrk = nullptr;
        delete secondTrk; secondTrk = nullptr;
        delete thirdTrk; thirdTrk = nullptr;
        delete fourthTrk; fourthTrk = nullptr;


    }
};

int main() {
    std::cout << ": ";
    std::string cmd;
    Player* SonyWalkman = new Player ();
    while (cmd != "exit"){
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