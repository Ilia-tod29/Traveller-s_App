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

    char* getData() const;

    bool operator==(const String& other);

    bool operator!=(const String& other);

    String& operator+=(const String& other);

    String operator+(const String& other);

    void removeSpaces();

    char operator[](const size_t index)const;

    bool isEmpty() const;

    bool doesContain(const char& ch) const;

    String getExact(const size_t& start, const size_t& end) const;

    String leftPart(const char& separator) const;

    String rightPart(const char& separator) const;

    int toInt() const;

    friend std::ostream& operator<<(std::ostream& os, const String& str);

    friend std::istream& operator>>(std::istream& is, String& str);

    friend std::istream& getline (std::istream& stream, String& str, const char& end);

    ~String();
private:
    char* str;
    size_t size;
    void cpy(const String& other);
    void vanish();
};


#endif //TRAVELLER_S_APP_STRING_H
