//
// Created by Ilia on 5/1/2021.
//
#include "String.h"
#include <cstring>


size_t removeSpacesFromData(char* s)
{
    char* cpy = s;
    char* temp = s;
    size_t removed = 0;

    while (*cpy)
    {
        if (*cpy != ' ')
        {
            *temp++ = *cpy;
        }else {
            removed++;
        }
        cpy++;
    }
    *temp = 0;
    return removed;
}


void String::cpy(const String& other) {
    this->size = other.size;
    this->str = new char[strlen(other.str) + 1];
    strcpy(this->str, other.str);
}

void String::vanish() {
    if (this->str != nullptr) {
        delete[] this->str;
        this->str = nullptr;
    }
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

String String::operator+(const String &other) {
    String tempStr;
    tempStr.size = this->size + other.size;
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

bool String::operator!=(const String &other) {
    return !(*this == other);
}

String & String::operator+=(const String &other) {
    String tempStr = *this + other;
    *this = tempStr;
    return *this;
}

void String::removeSpaces() {
    this->size -= removeSpacesFromData(this->str);
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

bool String::doesContain(const char &ch) const {
    bool flag = false;
    for (int i = 0; i < this->size; ++i) {
        if (this->str[i] == ch) {
            flag = true;
            break;
        }
    }
    return flag;
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

int String::toInt() const {
    size_t temp = 0;
    for (int i = 0; i < this->size; ++i) {
        if(!(this->str[i] >= '0' && this->str[i] <= '9')) {
            return 0;
        }
        temp += ((size_t)this->str[i] - 48);
        temp *= 10;
    }
    temp /= 10;
    return temp;
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

std::istream& operator>>(std::istream& is, String& str) {

    delete[] str.str;
    char* container = new char[200];

    is.getline(container, 200);
    str.size = strlen(container);
    str.str = new char[str.size + 1];
    strcpy(str.str, container);

    return is;
}

std::istream& getline(std::istream& stream, String& str, const char& end)
{
    char ch;
    size_t i = 0;
    delete[] str.str;
    str.str = new char[200];
    while (stream.get(ch) && ch != end) {
        str.str[i] = ch;
        i++;
    }
    str.str[i] = '\0';
    str.size = i;
    return stream;
}