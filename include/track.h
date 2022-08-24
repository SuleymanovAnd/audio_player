#include <iostream>
#include <ctime>
#pragma once
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
    std::string getNameTrack ();
    std::tm getDateOfCreation();
    time_t getDuration ();
};