//
// Created by Ilia on 5/1/2021.
//

#ifndef TRAVELLER_S_APP_AUTH_H
#define TRAVELLER_S_APP_AUTH_H

#include <iostream>
#include "User.h"
#include "String.h"
#include "Vector.h"

class Auth {
public:
    Auth() : username(""), password("") {};

    Auth(const String& _username, const String& _password);

    User logIn(const Vector<User>& allUsers) const;

    // The ID is auto-counted int the main
    // Could be changed - username and password to be from data members
    User signUp(const int& _id, const String& _username, const String& _password, const String& _eMail);

private:
    String username;
    String password;
};

//namespace Auth {
//    User logIn() {
//
//    }
//
//}




#endif //TRAVELLER_S_APP_AUTH_H
