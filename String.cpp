//
// Created by Ilia on 5/1/2021.
//
#include "String.h"
#include <cstring>
void String::cpy(const String& other) {
    this->size = other.size;
    this->str = new char[strlen(other.str) + 1];
    strcpy(this->str, other.str);
//    for (int i = 0; i < other.size; ++i) {
//        this->str[i] = other.str[i];
//    }
//    this->str[this->size] = '\0';
}

void String::vanish() {
    delete[] this->str;
    this->str = nullptr;
}

String::String() : str(nullptr), size(0) {}

String::String(const char *data) {
    this->size = strlen(data);
    this->str = new char[this->size + 1];
    strcpy(this->str, data);
}

String::String(const String &other) {
    cpy(other);
}

String & String::operator=(const String &other) {
    if (this != &other) {
        vanish();
        cpy(other);
    }
    return *this;
}

size_t String::length() const {
    return this->size;
}

char * String::getData() const {
    return this->str;
}

//Possible issues
String String::operator+(const String &other) {
    String tempStr;
    tempStr.size = this->size + other.size - 1;
    tempStr.str = new char[tempStr.size];
    for (int i = 0; i < this->size; ++i) {
        tempStr.str[i] = this->str[i];
    }
    for (int i = 0; i < other.size; ++i) {
        tempStr.str[i + this->size] = other.str[i];
    }
    tempStr.str[tempStr.size] = '\0';
    return tempStr;
}

bool String::operator==(const String &other) {
    if(this->size == other.size) {
        bool flag = true;
        for (int i = 0; i < this->size; ++i) {
            if(this->str[i] != other.str[i]) {
                flag = false;
                break;
            }
        }
        if(flag) {
            return true;
        }
        return false;
    }
    return false;
}

String & String::operator+=(const String &other) {
    String tempStr = *this + other;
    *this = tempStr;
    return *this;
}

char String::operator[](const size_t index) const {
    if (index > this->size) {
        exit(1);
    }
    return this->str[index];
}

bool String::isEmpty() const {
    if (this->size == 0) {
        return true;
    }
    return false;
}

String String::getExact(const size_t &start, const size_t &end) const {
    String temp;
    temp.str = new char[end - start + 1];
    for (int i = start; i <= end; ++i) {
        temp.str[i - start] = this->str[i];
        temp.size++;
    }
    temp.str[end - start + 1] = '\0';
    return temp;
}

String String::leftPart(const char &separator) const {
    String result;
    size_t findSize = 0;
    while (this->str[findSize] != separator) {
        findSize++;
        if(findSize == this->size) {
            break;
        }
    }
    result.str = new char[findSize];
    for (int i = 0; i < findSize; ++i) {
        result.str[i] = this->str[i];
    }
    result.str[findSize] = '\0';
    result.size = findSize;

    return result;
}

String String::rightPart(const char &separator) const {
    String result;
    size_t findPosition = 0;
    while (this->str[findPosition] != separator) {
        findPosition++;
        if(findPosition == this->size) {
            break;
        }
    }

    if (findPosition == this->size) {
        result = *this;
        return result;
    }

    result.str = new char[this->size - findPosition - 1];
    for (int i = findPosition + 1; i < this->size; ++i) {
        result.str[i - (findPosition + 1)] = this->str[i];
    }
    result.str[this->size - findPosition - 1] = '\0';
    result.size = this->size - findPosition - 1;

    return result;
}

String::~String() {
    vanish();
}

std::ostream& operator<<(std::ostream& os, const String& str) {
    for (int i = 0; i < str.size; ++i) {
        os << str.str[i];
    }
    return os;
}
