//
// Created by Ilia on 5/1/2021.
//

#include "Auth.h"

HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);

bool is_email_valid(const String& email)
{
    // define a regular expression
    const std::regex pattern ("(\\w+)(\\.|_)?(\\w*)@(\\w+)(\\.(\\w+))+");

    // try to match the string with the regular expression
    return std::regex_match(email.getData(), pattern);
}


Auth::Auth(const String &_username, const String &_password) : username(_username), password(_password) {}

User Auth::logIn(const Vector<User> &allUsers) const {
    User userAuth;
    bool flag = false;
    for (int i = 0; i < allUsers.getSize(); ++i) {
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
        SetConsoleTextAttribute(hConsole, 4);
        std::cout << "Incorrect username or password!\n";
        SetConsoleTextAttribute(hConsole, 7);
        return userAuth;
    }
}

User Auth::signUp(const int &_id, const String &_eMail) {
    User newUser;
    if(is_email_valid(_eMail)) {
        newUser.setAuth(_id, this->username, this->password, _eMail);
        return newUser;
    }
    else {
        SetConsoleTextAttribute(hConsole, 4);
        std::cout << "Invalid eMail format!\n";
        SetConsoleTextAttribute(hConsole, 7);
        newUser.setAuth(-1, "", "", "");
        return newUser;
    }
}