//
// Created by Ilia on 5/1/2021.
//

#ifndef TRAVELLER_S_APP_STRING_H
#define TRAVELLER_S_APP_STRING_H

#include <iostream>


class String {
public:
    String();

    String(const char* data);

    String(const String& other);

    String& operator=(const String& other);

    size_t length() const;

    String& operator+=(const String& other);

    String operator+(const String& other);

    char operator[](const size_t index)const;

    friend std::ostream& operator<<(std::ostream& os, const String& str);

    ~String();
private:
    char* str;
    size_t size;
    void cpy(const String& other);
    void vanish();
};


#endif //TRAVELLER_S_APP_STRING_H
