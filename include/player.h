#include "track.h"
#pragma once
class Player {
    Track* firstTrk = new Track ("Sting - Shape of my heart",1993,9,281);
    Track* secondTrk = new Track ("Deep purple - Smoke on the water",1971,06,343);
    Track* thirdTrk = new Track ( "Queen - Bohemian Rhapsody",1975,11,355);
    Track* fourthTrk = new Track ("Beatles - Yesterday",1965,9,123);

    bool playingSong = false;
    bool pauseSong = false;
    static void playing (Track* Trk){
        std::cout << "Now playing: " << Trk->getNameTrack () << " || " << Trk->getDateOfCreation().tm_year
                  << "/" << Trk->getDateOfCreation().tm_mon << " || " << Trk->getDuration () /60 << " min. "
                  << Trk->getDuration () %60 << " sec.\n";
    }

public:
    void play ();
    void pause ();
    void next ();
    void stop();
    void exit ();
};
