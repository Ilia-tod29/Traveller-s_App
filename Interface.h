//
// Created by Ilia on 5/6/2021.
//

#ifndef TRAVELLER_S_APP_INTERFACE_H
#define TRAVELLER_S_APP_INTERFACE_H

#include <iostream>
#include <fstream>
#include <cmath>

#include "String.h"
#include "Vector.h"
#include "User.h"
#include "Auth.h"
#include "Journey.h"



namespace interface {
    void commands() {
        std::cout << ">1: Log in.\n";
        std::cout << ">2: Sign up.\n";
        std::cout << ">3: Exit.\n";
    }

    void commandsLoggedIn() {
        std::cout << ">1: Add journey.\n";
        std::cout << ">2: Add friend.\n";
        std::cout << ">3: Friends list.\n";
        std::cout << ">4: Check your friends opinion over a destination.\n";
        std::cout << ">5: Check the grades for a destination.\n";
        std::cout << ">6: All destinations.\n";
        std::cout << ">7: Log out.\n";
        std::cout << ">8: Exit.\n";
    }


    void pushUserToDB(const User &currUser) {
        std::ofstream pushUser("users.db.txt", std::ios_base::app);
        if (pushUser.is_open()) {
            pushUser << "\n" << currUser.getId() << "|" << currUser.getUsername() << "|" << currUser.getPassword()
                     << "|" << currUser.getEMail();
            pushUser.close();
            String extension(".db.txt");
            String DB = currUser.getUsername() + extension;
            std::ofstream pushJourney(DB.getData());
            pushJourney.close();
        } else {
            std::cout << "Unable to open the file \n";
        }
    }


    void readUsersFromDB(Vector<User> &allUsers) {
        User currUser;
        String _id, _username, _password, _eMail;
        std::ifstream usersDB("users.db.txt");
        if (usersDB.is_open()) {
            while (!usersDB.eof()) {
                getline(usersDB, _id, '|');
                getline(usersDB, _username, '|');
                getline(usersDB, _password, '|');
                getline(usersDB, _eMail, '\n');

                currUser.setAuth(_id.toInt(), _username, _password, _eMail);
                allUsers.pushBack(currUser);
            }
            usersDB.close();
        } else {
            std::cout << "Unable to open the file \n";
        }
    }

    void setJourney(Journey &newJourney) {
        String _destination, _timePeriod, _comment, _grade, _ph;
        size_t phLength;
        std::cout << "Enter destination /Town, Country/: ";
        std::cin >> _destination;
        std::cout << "Enter time period /YYYY-MM-DD/YYYY-MM-DD/: ";
        std::cin >> _timePeriod;
        std::cout << "Enter grade /1 - 5/: ";
        std::cin >> _grade;
        std::cout << "Enter comment: ";
        std::cin >> _comment;

        std::cout << "Enter photos count: ";
        std::cin >> phLength;
        std::cin.ignore();
        for (int i = 0; i < phLength; ++i) {
            std::cout << "Enter photo No" << i + 1 << ":";
            std::cin >> _ph;
            newJourney.addPhoto(_ph);
        }

        newJourney.setDestination(_destination);
        newJourney.setTimePeriod(_timePeriod);
        newJourney.setGrade(_grade);
        newJourney.setComment(_comment);
    };

    void pushJourneyToDB(const Journey &currJourney, const User &currUser) {
        String extension(".db.txt");
        String DB = currUser.getUsername() + extension;
        std::ofstream pushJourney(DB.getData(), std::ios_base::app);
        if (pushJourney.is_open()) {
            pushJourney << "\n" << currJourney.getDestination() << "|" << currJourney.getTimePeriod() << "|"
                        << currJourney.getGrade() << "|" << currJourney.getComment() << "|" << currJourney.getPhotos();
            pushJourney.close();
        } else {
            std::cout << "Unable to open the file \n";
        }
    };

    bool is_empty(std::ifstream &pFile) {
        return pFile.peek() == std::ifstream::traits_type::eof();
    }

    //TODO finish the function with setting the friends
    void userSetUp(User &currUser) {
        String extension(".db.txt");
        String file = currUser.getUsername() + extension;
        String _destination, _timePeriod, _grade, _comment, _photos;

        std::ifstream userDB(file.getData());

        if (userDB.is_open()) {
            if (!is_empty(userDB)) {
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
            }
            userDB.close();
        } else {
            std::cout << "Unable to open the file: " << file << "\n";
        }
    }

    User logIn(const Vector<User> &allUsers) {
        String username, password;

        std::cout << "Enter username:";
        std::cin >> username;

        std::cout << "Enter password:";
        std::cin >> password;

        Auth login(username, password);

        return login.logIn(allUsers);
    }


    User signUp(const size_t &id) {
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


    void allDestinations(const Vector<User> &allUsers) {
        std::cout << "We have information about these destinations:\n";
        for (int i = 0; i < allUsers.getSize(); ++i) {
            for (int j = 0; j < allUsers[i].getJourneys().getSize(); ++j) {
                std::cout << allUsers[i].getJourneys()[j].getDestination() << "\n";
            }
        }
    }

    void getFriendsReview(const User &currUser) {
        String Town, Country;
        std::cout << "Enter your wished destination:\n";
        std::cout << "Town: ";
        std::cin >> Town;
        std::cout << "Country: ";
        std::cin >> Country;

        Vector<User> tempUsers = currUser.friendsVisitedADestination(Town, Country);
        if (tempUsers.getSize() > 0) {
            for (int i = 0; i < tempUsers.getSize(); ++i) {
                for (int j = 0; j < tempUsers[i].getJourneys().getSize(); ++j) {
                    if (tempUsers[i].getJourneys()[j].getTown() == Town &&
                        tempUsers[i].getJourneys()[j].getCountry() == Country) {
                        std::cout << tempUsers[i].getUsername() << ": " << tempUsers[i].getJourneys()[j].getComment()
                                  << "\n";
                    }
                }
            }
        } else {
            std::cout << "No friends visited this destination.\n";
        }
    }

    void getGrades(const Vector<User> &allUsers) {
        String Town, Country;
        std::cout << "Enter your wished destination:\n";
        std::cout << "Town: ";
        std::cin >> Town;
        std::cout << "Country: ";
        std::cin >> Country;
        size_t sumGrades = 0, counter = 0;
        for (int i = 0; i < allUsers.getSize(); ++i) {
            for (int j = 0; j < allUsers[i].getJourneys().getSize(); ++j) {
                if (allUsers[i].getJourneys()[j].getTown() == Town &&
                    allUsers[i].getJourneys()[j].getCountry() == Country) {
                    std::cout << allUsers[i].getUsername() << ": " << allUsers[i].getJourneys()[j].getGrade() << "\n";
                    sumGrades += allUsers[i].getJourneys()[j].getGrade();
                    counter++;
                }
            }
        }
        std::cout << "Average for this destination: "
                  << std::ceil(((float) sumGrades / (float) counter) * 100.0) / 100.0 << "\n";
    }

    void getAllDestinations(const Vector<User> &allUsers) {
        Vector<String> destinations;
        std::cout << "All destinations:\n";
        for (int i = 0; i < allUsers.getSize(); ++i) {
            for (int j = 0; j < allUsers[i].getJourneys().getSize(); ++j) {
                destinations.pushBack(allUsers[i].getJourneys()[j].getDestination());
            }
        }
        for (int i = 0; i < destinations.getSize(); ++i) {
            std::cout << destinations[i] << "\n";
        }
    }
}
#endif //TRAVELLER_S_APP_INTERFACE_H
