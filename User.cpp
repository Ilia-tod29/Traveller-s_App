//
// Created by Ilia on 5/1/2021.
//

#include "User.h"


void User::setAuth(const int &_id, const String &_username, const String &_password, const String &_eMail) {
    this->id = _id;
    this->username = _username;
    this->password = _password;
    this->eMail = _eMail;
}

void User::operator=(const User &other) {
    this->id = other.id;
    this->username = other.username;
    this->password = other.password;
    this->eMail = other.eMail;
    this->friends = other.friends;
    this->journeys = other.journeys;
}

void User::addFriend(User *newFriend) {
    this->friends.pushBack(newFriend);
}



void User::setJourney(const Journey &newJourney) {
    this->journeys.pushBack(newJourney);
}

int User::getId() const {
    return this->id;
}

String User::getUsername() const{
    return this->username;
}

String User::getPassword() const {
    return this->password;
}

String User::getEMail() const {
    return this->eMail;
}

Vector<Journey> User::getJourneys() const {
    return this->journeys;
}

Vector<User*> User::getFriends() const {
    return this->friends;
}


// Must be checked
Vector<User> User::friendsVisitedADestination(const String &town, const String &country) const {
    Vector<User> friendsVisited;
    for (int i = 0; i < this->friends.getSize(); ++i) {
        for (int j = 0; j < this->friends.getData()[i]->getJourneys().getSize(); ++j) {
            if (this->friends.getData()[i]->getJourneys().getData()[j].getTown() == town && this->friends.getData()[i]->getJourneys().getData()[j].getCountry() == country) {
                friendsVisited.pushBack(*this->friends[i]);
            }
        }
    }
    return friendsVisited;
}

bool User::operator==(const User &other) const {
    return this->id == other.id && this->getUsername() == other.username && this->getUsername() == other.password;
}

void User::showFriends() const {
    for (int i = 0; i < this->friends.getSize(); ++i) {
        std::cout << this->friends[i]->getUsername() << "\n";
    }
}