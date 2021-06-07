//
// Created by Ilia on 5/1/2021.
//

#ifndef TRAVELLER_S_APP_AUTH_H
#define TRAVELLER_S_APP_AUTH_H

#include <iostream>
#include <regex>

#include "User.h"
#include "String.h"
#include "Vector.h"

class Auth {
public:
    Auth() : username(""), password("") {};

    Auth(const String& _username, const String& _password);

    User logIn(const Vector<User>& allUsers) const;

    // The ID is auto-counted in the main
    // Could be changed - username and password to be from data members
    User signUp(const int& _id, const String& _eMail);

    String getUsername ()const;
    String getPassword () const;

private:
    String username;
    String password;
};





#endif //TRAVELLER_S_APP_AUTH_H
