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

String::~String() {
    vanish();
}

std::ostream& operator<<(std::ostream& os, const String& str) {
    for (int i = 0; i < str.size; ++i) {
        os << str.str[i];
    }
    return os;
}
