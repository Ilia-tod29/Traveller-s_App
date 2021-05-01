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
    
private:
    Destination destination;
    TimePeriod timePeriod;
    size_t grade;
    String comment;
    Vector<String> photos;
};


#endif //TRAVELLER_S_APP_JOURNEY_H
