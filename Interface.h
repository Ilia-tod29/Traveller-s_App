//
// Created by Ilia on 5/6/2021.
//

#ifndef TRAVELLER_S_APP_INTERFACE_H
#define TRAVELLER_S_APP_INTERFACE_H

#include <iostream>
#include <fstream>

#include "Auth.h"



namespace interface {
    User logIn(const Vector<User>& allUsers) {
        String username, password;

        std::cout << "Enter username:";
        std::cin >> username;

        std::cout << "Enter password:";
        std::cin >> password;

        Auth login(username, password);
        return login.logIn(allUsers);
    }

    //TODO finish the function with setting the friends
    void userSetUp(User& currUser){
        String extension(".db.txt");
        String file = currUser.getUsername() + extension;
        String _destination, _timePeriod, _grade, _comment, _photos;

        Vector<User> friends;

        std::ifstream userDB(file.getData());
        std::cout << file.getData() << "\n";

        if(userDB.is_open()){
            while (!userDB.eof()) {
                Journey newJourney;
                getline(userDB, _destination, '|');
                newJourney.setDestination(_destination);

                getline(userDB, _timePeriod, '|');
                newJourney.setTimePeriod(_timePeriod);

                getline(userDB, _grade, '|');
                newJourney.setGrade(_grade);

                getline(userDB, _comment, '|');
                newJourney.setComment(_comment);

                getline(userDB, _photos, '\n');
                newJourney.setAndSeparatePhotos(_photos);

                currUser.setJourney(newJourney);
            }
            userDB.close();
        }
        else {
            std::cout << "Unable to open the file \n";
        }
    }



    User signUp(const size_t& id) {
        String username, password, eMail;
        std::cout << "Enter username:";
        std::cin >> username;

        std::cout << "Enter password:";
        std::cin >> password;

        std::cout << "Enter e-mail:";
        std::cin >> eMail;

        Auth signup(username, password);
        return signup.signUp(id, eMail);
    };





}



#endif //TRAVELLER_S_APP_INTERFACE_H
