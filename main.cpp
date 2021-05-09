#include <iostream>

#include "Vector.h"
#include "String.h"
#include "Journey.h"
#include "User.h"
#include "Interface.h"

using namespace interface;
int main() {
    Vector<User> allUsers;
    User currentUser;
    String command, confirmation;
    int currentId;
    bool isLoggedIn = false;

    interface::readUsersFromDB(allUsers);
    for (int i = 0; i < allUsers.getSize(); ++i) {
        interface::userSetUp(allUsers[i]);
    }
    currentId = allUsers.getSize();


    while(true) {
        std::cout << "{---------------TRAVELLER'S APP---------------}\n";
        if(isLoggedIn) {
            std::cout << "->Hello, " << currentUser.getUsername() << "!\n";
            interface::commandsLoggedIn();
            std::cout << "Enter a number of a command: ";
            std::cin >> command;

            if (command == "1") {
                Journey newJourney;
                interface::setJourney(newJourney);
                interface::pushJourneyToDB(newJourney, currentUser);
            }
            else if (command == "2") {
                String _username;
                bool success = false;
                std::cout << "Enter new friend's username:";
                std::cin >> _username;
                for (int i = 0; i < allUsers.getSize(); ++i) {
                    if(allUsers[i].getUsername() == _username) {
                        currentUser.addFriend(&allUsers[i]);
                        success = true;
                    }
                }
                if(success) {
                    std::cout << "Successfully added!\n";
                }
                else{
                    std::cout << "There is no such user in our system.\n";
                }
//                Vector<User*> u1 = currentUser.getFriends();
//                u1.getSize();
            }
            else if (command == "3") {
                std::cout << "---------------------------\n";
                std::cout << "Your friends:\n";
                for (int i = 0; i < currentUser.getFriends().getSize(); ++i) {
                    std::cout << currentUser.getFriends()[i]->getUsername() << "\n";
                }
                std::cout << "---------------------------\n";
            }
            else if (command == "4") {
                std::cout << "---------------------------\n";
                interface::getFriendsReview(currentUser);
                std::cout << "---------------------------\n";
            }
            else if (command == "5") {
                std::cout << "---------------------------\n";
                interface::getGrades(allUsers);
                std::cout << "---------------------------\n";
            }
            else if (command == "6") {
                std::cout << "---------------------------\n";
                interface::getAllDestinations(allUsers);
                std::cout << "---------------------------\n";
            }
            else if (command == "7") {
                currentUser.clear();
                isLoggedIn = false;
            }
            else if (command == "8") {
                while (confirmation != "Y" && confirmation != "N") {
                    std::cout << "Are you sure you want to exit? (Y/N): ";
                    std::cin >> confirmation;
                }
            }
            else {
                std::cout << "Invalid command!\n";
            }

            if (command == "8" && confirmation == "Y") {
                break;
            }
        }
        else {
            interface::commands();
            std::cout << "Enter a number of a command: ";
            std::cin >> command;
            if (command == "1") {
                currentUser = interface::logIn(allUsers);

                if(currentUser.getId() != -1) {
                    isLoggedIn = true;
                }
            }
            else if (command == "2") {
                currentUser = interface::signUp(currentId);
                currentId++;
                interface::pushUserToDB(currentUser);
                    isLoggedIn = true;
            }
            else if (command == "3") {
                while (confirmation != "Y" && confirmation != "N") {
                    std::cout << "Are you sure you want to exit? (Y/N): ";
                    std::cin >> confirmation;
                }
            }
            else {
                std::cout << "Invalid command!\n";
            }

            if (command == "3" && confirmation == "Y") {
                break;
            }
        }
    }

    return 0;
}
