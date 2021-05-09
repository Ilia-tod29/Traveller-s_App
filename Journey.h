//
// Created by Ilia on 5/1/2021.
//

#ifndef TRAVELLER_S_APP_JOURNEY_H
#define TRAVELLER_S_APP_JOURNEY_H

#include <iostream>
#include <time.h>
#include "String.h"
#include "Vector.h"


class Journey {
public:
    void setDestination(const String& _destination);

    void setTimePeriod(const String& _timePeriod); // VALIDATION!

    void setGrade(const size_t& _grade); // VALIDATION!

    void setGrade(const String& _grade); // VALIDATION!

    void setComment(const String& _comment);

    void addPhoto(const String& _photo); // VALIDATION!

    void setAndSeparatePhotos(const String& _photos); // VALIDATION!

    String getDestination() const;

    String getTimePeriod() const;

    size_t getGrade () const;

    String getComment() const;

    String getPhotos() const;

    String getTown() const;

    String getCountry() const;

    void display() const;
private:
    String destination;
    String timePeriod;
    size_t grade;
    String comment;
    Vector<String> photos;
};


#endif //TRAVELLER_S_APP_JOURNEY_H
