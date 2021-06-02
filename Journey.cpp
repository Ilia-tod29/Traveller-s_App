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

void Journey::setDestination(const String &_destination) {
    if (_destination.doesContain(',')) {
        this->destination = _destination;
    }
    else {
        HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
        SetConsoleTextAttribute(hConsole, 4);
        std::cout << "Invalid destination format!\n";
        SetConsoleTextAttribute(hConsole, 7);
    }
}

void Journey::setTimePeriod(const String &_timePeriod) {
    size_t startYear, startMonth, startDay, endYear, endMonth, endDay;
    startYear = getDateLength(0, 3, _timePeriod.getExact(0, 3));
    startMonth = getDateLength(5, 6, _timePeriod.getExact(5, 6));
    startDay = getDateLength(8, 9, _timePeriod.getExact(8, 9));
    endYear = getDateLength(11, 14, _timePeriod.getExact(11, 14));
    endMonth = getDateLength(16, 17, _timePeriod.getExact(16, 17));
    endDay = getDateLength(19, 20, _timePeriod.getExact(19, 20));

    bool periodValidation = (startYear < endYear) || (startYear == endYear && ((startMonth < endMonth) || (startMonth == endMonth && startDay < endDay)));
    bool dateValidation = isDateValid(startMonth, startDay, startYear) && isDateValid(endMonth, endDay, endYear);
    if (periodValidation && dateValidation) {
        this->timePeriod = _timePeriod;
    }
    else {
        HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
        this->timePeriod = "Invalid period";
        SetConsoleTextAttribute(hConsole, 4);
        std::cout << "Invalid time period or date! \n";
        SetConsoleTextAttribute(hConsole, 7);
    }
}

void Journey::setGrade(const size_t &_grade) {
    if (_grade >= 1 && _grade <= 5) {
        this->grade = _grade;
    }
    else {
        HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
        SetConsoleTextAttribute(hConsole, 4);
        std::cout << "Invalid grade! \n";
        SetConsoleTextAttribute(hConsole, 7);
    }
}

void Journey::setGrade(const String &_grade) {
    if(_grade.length() == 1) {
        size_t grade = (size_t)_grade.getData()[0] - 48;
        if (grade >= 1 && grade <= 5) {
            this->grade = grade;
        }
        else {
            HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
            this->grade = 6;
            SetConsoleTextAttribute(hConsole, 4);
            std::cout << "Invalid grade! \n";
            SetConsoleTextAttribute(hConsole, 7);
        }
    }
    else {
        HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
        this->grade = 6;
        SetConsoleTextAttribute(hConsole, 4);
        std::cout << "Invalid grade! \n";
        SetConsoleTextAttribute(hConsole, 7);
    }
}

void Journey::setComment(const String &_comment) {
    this->comment = _comment;
}

void Journey::addPhoto(const String &_photo) {
    size_t i = 0;
    String name = _photo.leftPart('.');
    String extension = _photo.rightPart('.');
    while ((name.getData()[i] >= 'A' && name.getData()[i] <= 'Z') || (name.getData()[i] >= 'a' && name.getData()[i] <= 'z') || name.getData()[i] == '_') {
        i++;
    }

    if(i == name.length() && i != 0 && (extension == "jpeg" || extension == "png")) {
        this->photos.pushBack(_photo);
    }
    else {
        HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
        SetConsoleTextAttribute(hConsole, 4);
        std::cout << "Invalid image format or name! \n";
        SetConsoleTextAttribute(hConsole, 7);
    }
}

void Journey::setAndSeparatePhotos(const String &_photos) {
    String ph = _photos;
    while(ph.length() != 0) {
        this->addPhoto(ph.leftPart(','));
        if (ph == ph.rightPart(',')) {
            break;
        }
        ph = ph.rightPart(',');
    }

}
//
//void Journey::setAndSeparatePhotos(const String &_photos) {
//    String ph = _photos;
//    while(ph.length() != 0) {
//        std::cout << ph.leftPart(',') << std::endl;
//        std::cout << ph.rightPart(',') << std::endl;
//        std::cout << std::boolalpha << (ph == ph.rightPart(',')) << std::endl;
////        std::cout << ph;
//        if (ph == ph.rightPart(',')) {
//            this->addPhoto(ph);
//            std::cout <<"." << std::endl;
//            break;
//        }
//        this->addPhoto(ph.leftPart(','));
//        ph = ph.rightPart(',');
//    }

//}

void Journey::erasePhotos() {
    this->photos.eraseData();
}

String Journey::getDestination() const {
    return this->destination;
}

String Journey::getTimePeriod() const {
    return this->timePeriod;
}

size_t Journey::getGrade() const {
    return this->grade;
}

String Journey::getComment() const {
    return this->comment;
}

String Journey::getPhotos() const {
    String allPhotos;
    for (int i = 0; i < this->photos.getSize(); ++i) {
        if(i != this->photos.getSize() - 1) {
            allPhotos += (this->photos[i] + ",");
        }
        else {
            allPhotos += this->photos[i];
        }
    }
    return allPhotos;
}

String Journey::getTown() const {
    return this->destination.leftPart(',');
}

String Journey::getCountry() const {
    String country = this->destination.rightPart(',');
    country.removeSpaces();
    return country;
}

void Journey::display() const {
    std::cout << "Destination: " << this->destination << "\n";
    std::cout << "Time period: " << this->timePeriod << "\n";
    std::cout << "Grade: " << this->grade << "\n";
    std::cout << "Comment: " << this->comment << "\n";
    std::cout << "Photos: \n";
    this->photos.print();
}