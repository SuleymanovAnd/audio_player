#include "track.h"

std::string Track::getNameTrack (){
    return nameTrack;
}

std::tm Track::getDateOfCreation(){
    return dateOfCreation;
}

time_t Track::getDuration () {
    return duration;
}
