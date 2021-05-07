//
// Created by Ilia on 5/1/2021.
//

#include "Auth.h"

Auth::Auth(const String &_username, const String &_password) : username(_username), password(_password) {}

User Auth::logIn(const Vector<User> &allUsers) const {
    User userAuth;
    bool flag = false;
    for (int i = 0; i < allUsers.getSize(); ++i) {
//        std::cout << "HI \n";
        if(allUsers[i].getUsername() == this->username && allUsers[i].getPassword() == this->password) {
            userAuth = allUsers[i];
            flag = true;
            break;
        }
    }
    if (flag) {
       return userAuth;
    }
    // Otherwise returns user initialized with id of (-1);
    else {
        std::cout << "Incorrect username ot password! \n";
        return userAuth;
    }
}

User Auth::signUp(const int &_id, const String &_eMail) {
    User newUser;
    newUser.setAuth(_id, this->username, this->password, _eMail);
    return newUser;
}