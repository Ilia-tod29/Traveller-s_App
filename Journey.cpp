//
// Created by Ilia on 5/1/2021.
//


#include "Journey.h"

size_t getDateLength(const size_t &start, const size_t &end, const String &partOfDate) {
    size_t temp = 0;
    for (int i = 0; i < partOfDate.length(); ++i) {
        temp += ((size_t)partOfDate.getData()[i] - 48);
        temp *= 10;
    }
    temp /= 10;
    return temp;
}

bool leapYear(size_t year) {
    return (year % 400 == 0) || (year % 4 == 0 && year % 100 != 0);
}

bool isDateValid(size_t month, size_t day, size_t year)
{
    bool validation = true;
    if(!(year >= 1600 && year <=2100))
        validation = false;

    if(day < 1)
        validation = false;

    switch(month)
    {
        case 2:
            if(leapYear(year)) // We only care about leap years in February
                if(day > 29)
                    validation = false;
                else
                if(day > 28)
                    validation = false;
            break;
        case 1: case 3: case 5: case 7: case 8: case 10: case 12:
            if(day > 31)
                validation = false;
            break;
        case 4: case 6: case 9: case 11:
            if(day > 30)
                validation = false;
            break;
        default: // the month is not between 1 and 12
            validation = false;
            break;
    }
    return validation;
}

void Journey::setDestionation(const String &_destination) {
    this->destination = _destination;
}

void Journey::setTimePeriod(const String &_timePeriod) {
    size_t startYear, startMonth, startDay, endYear, endMonth, endDay;
    startYear = getDateLength(0, 3, _timePeriod.getExact(0, 3));
    startMonth = getDateLength(5, 6, _timePeriod.getExact(5, 6));
    startDay = getDateLength(8, 9, _timePeriod.getExact(8, 9));
    endYear = getDateLength(11, 14, _timePeriod.getExact(11, 14));
    endMonth = getDateLength(16, 17, _timePeriod.getExact(16, 17));
    endDay = getDateLength(19, 20, _timePeriod.getExact(19, 20));

    std::cout << startYear << " " << startMonth << " " << startDay << " " << endYear << " " << endMonth << " " << endDay << " " << "\n";
    bool periodValidation = (startYear < endYear) || (startYear == endYear && ((startMonth < endMonth) || (startMonth == endMonth && startDay < endDay)));
    bool dateValidation = isDateValid(startMonth, startDay, startYear) && isDateValid(endMonth, endDay, endYear);
    if (periodValidation && dateValidation) {
        this->timePeriod = _timePeriod;
        std::cout << this->timePeriod << "\n";
    }
    else {
        std::cout << "Invalid time period or date! \n";
    }
}

void Journey::setGrade(const size_t &_grade) {
    if (_grade >= 1 && _grade <= 5) {
        this->grade = _grade;
    }
    else {
        std::cout << "Invalid grade! \n";
    }
}

void Journey::setComment(const String &_comment) {
    this->comment = _comment;
}

void Journey::addPhoto(const String &_photo) {
    size_t i = 0;
    String name = _photo.leftPart('.');
    String extension = _photo.rightPart('.');
    String validExtension("jpeg"), validExtension1("png");
    while ((name.getData()[i] >= 'A' && name.getData()[i] <= 'Z') || (name.getData()[i] >= 'a' && name.getData()[i] <= 'z') || name.getData()[i] == '_') {
        i++;
    }

    if(i == name.length() && i != 0 && (extension == validExtension || extension == validExtension1)) {
        this->photos.pushBack(_photo);
        this->photos.print();
    }
    else {
        std::cout << "Invalid image format or name! \n";
    }
}

String Journey::getTown() {
    return this->destination.leftPart(',');
}

String Journey::getCountry() {
    return this->destination.rightPart(',');
}