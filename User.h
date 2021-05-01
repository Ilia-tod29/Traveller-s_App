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
    void setAuth(const size_t& _id, const String& _username, const String& _password, const String& _eMail);

    void setFriend(const User& newFriend);

    void setJourney(const Journey& newJourney);

    String friendsVisitedADestination(const String& town, const String& country);

    Vector<String> getFeedbacks(const Vector<User> traveller);
private:
    size_t id;
    String username;
    String eMail;

    Vector<User> friends;
    Vector<Journey> journeys;
protected:
    String password;
};


#endif //TRAVELLER_S_APP_USER_H
