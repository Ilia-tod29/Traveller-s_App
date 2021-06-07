#define DOCTEST_CONFIG_IMPLEMENT
#include <iostream>
#include <windows.h>
#include <regex>

#include "Vector.h"
#include "String.h"
#include "Journey.h"
#include "User.h"
#include "Auth.h"
#include "Interface.h"
#include "doctest.h"
#include "myDocTests.h"

using namespace myInterface;
int main() {
//    doctest::Context().run();
//    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
//    Vector<User> allUsers;
//    User currentUser;
//    String command;
//    char confirmation;
//    int currentId;
//    bool isLoggedIn = false;
//
//    myInterface::readUsersFromDB(allUsers);
//    for (int i = 0; i < allUsers.getSize(); ++i) {
//        myInterface::userSetUp(allUsers[i]);
//    }
//    currentId = allUsers.getSize();
//
//    while(true) {
//        SetConsoleTextAttribute(hConsole, 14);
//        std::cout << "{---------------TRAVELLER'S APP---------------}\n";
//        SetConsoleTextAttribute(hConsole, 7);
//        if(isLoggedIn) {
//            SetConsoleTextAttribute(hConsole, 10);
//            std::cout << ">Hello, " << currentUser.getUsername() << "!<\n";
//            SetConsoleTextAttribute(hConsole, 7);
//            myInterface::commandsLoggedIn();
//            std::cout << "Enter a number of a command: ";
//            std::cin >> command;
//
//            if (command == "1") {
//                Journey newJourney;
//                char confirm = 'T';
//                bool addNewJourney = true;
//
//                myInterface::setJourney(newJourney);
//                while(newJourney.getGrade() == 6 || newJourney.getTimePeriod() == "Invalid period" || !newJourney.getDestination().doesContain(',')) {
//                    SetConsoleTextAttribute(hConsole, 4);
//                    std::cout << "Invalid journey!\n";
//                    SetConsoleTextAttribute(hConsole, 7);
//                    while (confirm != 'Y' && confirm != 'N' && confirm != 'n' && confirm != 'y') {
//                        std::cout << "Add new one (Y/N):";
//                        std::cin >> confirm;
//                        std::cin.ignore();
//                    }
//                    if (confirm == 'Y' || confirm == 'y') {
//                        newJourney.erasePhotos();
//                        myInterface::setJourney(newJourney);
//                        confirm = 'T';
//                    }
//                    else {
//                        addNewJourney = false;
//                        break;
//                    }
//                }
//                if (addNewJourney) {
//                    myInterface::pushJourneyToDB(newJourney, currentUser);
//                    SetConsoleTextAttribute(hConsole, 10);
//                    std::cout << "Journey successfully added!\n";
//                    SetConsoleTextAttribute(hConsole, 7);
//                }
//            }
//            else if (command == "2") {
//                String _username;
//                bool success = false;
//                std::cout << "Enter new friend's username:";
//                std::cin >> _username;
//                for (int i = 0; i < allUsers.getSize(); ++i) {
//                    if(allUsers[i].getUsername() == _username) {
//                        currentUser.addFriend(&allUsers[i]);
//                        success = true;
//                    }
//                }
//                if(success) {
//                    SetConsoleTextAttribute(hConsole, 10);
//                    std::cout << "Successfully added!\n";
//                    SetConsoleTextAttribute(hConsole, 7);
//                }
//                else{
//                    SetConsoleTextAttribute(hConsole, 4);
//                    std::cout << "There is no such user in our system.\n";
//                    SetConsoleTextAttribute(hConsole, 7);
//                }
//            }
//            else if (command == "3") {
//                myInterface::showFriends(currentUser);
//            }
//            else if (command == "4") {
//                myInterface::getFriendsReview(currentUser);
//            }
//            else if (command == "5") {
//                myInterface::getGrades(allUsers);
//            }
//            else if (command == "6") {
//                myInterface::getAllDestinations(allUsers);
//            }
//            else if (command == "7") {
//                currentUser.clear();
//                isLoggedIn = false;
//            }
//            else if (command == "8") {
//                while (confirmation != 'Y' && confirmation != 'N' && confirmation != 'n' && confirmation != 'y') {
//                    std::cout << "Are you sure you want to exit? (Y/N): ";
//                    std::cin >> confirmation;
//                    std::cin.ignore();
//                }
//            }
//            else {
//                SetConsoleTextAttribute(hConsole, 4);
//                std::cout << "Invalid command!\n";
//                SetConsoleTextAttribute(hConsole, 7);
//            }
//
//            if (command == "8" && (confirmation == 'Y' || confirmation == 'y')) {
//                break;
//            }
//            else {
//                confirmation = ' ';
//            }
//        }
//        else {
//            myInterface::commands();
//            std::cout << "Enter a number of a command: ";
//            std::cin >> command;
//            if (command == "1") {
//                currentUser = myInterface::logIn(allUsers);
//
//                if(currentUser.getId() != -1) {
//                    isLoggedIn = true;
//                    SetConsoleTextAttribute(hConsole, 10);
//                    std::cout << "Log in successful!\n";
//                    SetConsoleTextAttribute(hConsole, 7);
//                }
//            }
//            else if (command == "2") {
//                currentUser = myInterface::signUp(currentId);
//
//                if(currentUser.getId() != -1) {
//                    currentId++;
//                    myInterface::pushUserToDB(currentUser);
//                    isLoggedIn = true;
//                    SetConsoleTextAttribute(hConsole, 10);
//                    std::cout << "Successfully registered!\n";
//                    SetConsoleTextAttribute(hConsole, 7);
//                }
//            }
//            else if (command == "3") {
//                while (confirmation != 'Y' && confirmation != 'N' && confirmation != 'n' && confirmation != 'y') {
//                    std::cout << "Are you sure you want to exit? (Y/N): ";
//                    std::cin >> confirmation;
//                    std::cin.ignore();
//                }
//            }
//            else {
//                SetConsoleTextAttribute(hConsole, 4);
//                std::cout << "Invalid command!\n";
//                SetConsoleTextAttribute(hConsole, 7);
//            }
//
//            if (command == "3" && (confirmation == 'Y' || confirmation == 'y')) {
//                break;
//            }
//            else {
//                confirmation = ' ';
//            }
//        }
//    }

int x =3;
if(1 < x < 5) {
    std::cout << "hi" << std::endl;
}
    return 0;
}
