//
// Created by Ilia on 5/1/2021.
//

#ifndef TRAVELLER_S_APP_JOURNEY_H
#define TRAVELLER_S_APP_JOURNEY_H

#include <iostream>
#include <time.h>
#include "String.h"
#include "Vector.h"

struct Destination {
    String town;
    String country;
};

struct TimePeriod {
    String startDate;
    String endDate;
};

class Journey {
public:
    void setDestination(const String& _destination);

    void setTimePeriod(const String& _timePeriod); // VALIDATION!

    void setGrade(const size_t& _grade); // VALIDATION!

    void setComment(const String& _comment);

    void addPhoto(const String& _photo); // VALIDATION!

    String getTown();

    String getCountry();

    void display();
private:
    String destination;
    String timePeriod;
    size_t grade;
    String comment;
    Vector<String> photos;
};


#endif //TRAVELLER_S_APP_JOURNEY_H
