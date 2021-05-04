//
// Created by Ilia on 5/1/2021.
//

#include "User.h"


void User::setAuth(const size_t &_id, const String &_username, const String &_password, const String &_eMail) {
    this->id = _id;
    this->username = _username;
    this->password = _password;
    this->eMail = _eMail;
}

void User::setFriend(const User &newFriend) {
    this->friends.pushBack(newFriend);
}

void User::setJourney(const Journey &newJourney) {
    this->journeys.pushBack(newJourney);
}

Vector<Journey> User::getJourneys() const {
    return this->journeys;
}

// Must be checked
Vector<User> User::friendsVisitedADestination(const String &town, const String &country) const {
    Vector<User> friendsVisited;
    for (int i = 0; i < this->friends.getSize(); ++i) {
        for (int j = 0; j < this->friends.getData()[i].getJourneys().getSize(); ++j) {
            if (this->friends.getData()[i].getJourneys().getData()[j].getTown() == town && this->friends.getData()[i].getJourneys().getData()[j].getCountry() == country) {
                friendsVisited.pushBack(this->friends[i]);
            }
        }
    }
    return friendsVisited;
}