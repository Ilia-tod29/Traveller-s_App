//
// Created by Ilia on 5/1/2021.
//

#ifndef TRAVELLER_S_APP_USER_H
#define TRAVELLER_S_APP_USER_H

#include <iostream>

#include "String.h"
#include "Vector.h"
#include "Journey.h"


class User {
public:
    User() : id(-1), username(""), password(""), eMail("") {};

    void operator=(const User& other);

    // Constructor with parameters(not all data members are set here)
    // The ID is auto-counted int the main
    void setAuth(const int& _id, const String& _username, const String& _password, const String& _eMail);

    void addFriend(User* newFriend);

    void setJourney(const Journey& newJourney);

    int getId() const;

    String getUsername() const;

    String getPassword() const;

    String getEMail() const;

    Vector<Journey> getJourneys() const;

    Vector<User*> getFriends() const;

    Vector<User> friendsVisitedADestination(const String& town, const String& country) const;

    bool operator==(const User& other) const;

    void showFriends() const;

    void clear();
private:
    int id;
    String username;
    String eMail;
    String password;

    Vector<User*> friends;
    Vector<Journey> journeys;
};


#endif //TRAVELLER_S_APP_USER_H
