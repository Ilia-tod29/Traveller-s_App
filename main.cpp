#include <iostream>
#include <windows.h>
#include <regex>

#include "Vector.h"
#include "String.h"
#include "Journey.h"
#include "User.h"
#include "Auth.h"
#include "Interface.h"


using namespace myInterface;
int main() {
    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    Vector<User> allUsers;
//    std::cout << "2" << "\n";
    User currentUser;
//    std::cout << "3" << "\n";
    String command;
//    std::cout << "4" << "\n";
    char confirmation;
//    std::cout << "5" << "\n";
    int currentId;
//    std::cout << "6" << "\n";
    bool isLoggedIn = false;

//    std::cout << "7" << "\n";
    myInterface::readUsersFromDB(allUsers);
    for (int i = 0; i < allUsers.getSize(); ++i) {
//        std::cout << "20" << "\n";
        myInterface::userSetUp(allUsers[i]);
    }
//    std::cout << "8" << "\n";
    currentId = allUsers.getSize();

//    std::cout << allUsers[3].getJourneys()[0].getCountry() << "\n";

//    std::cout << "9" << "\n";
    while(true) {
        SetConsoleTextAttribute(hConsole, 11);
        std::cout << "{---------------TRAVELLER'S APP---------------}\n";
        SetConsoleTextAttribute(hConsole, 7);
//        std::cout << "10" << "\n";
        if(isLoggedIn) {
            SetConsoleTextAttribute(hConsole, 10);
            std::cout << ">Hello, " << currentUser.getUsername() << "!<\n";
            SetConsoleTextAttribute(hConsole, 7);
            myInterface::commandsLoggedIn();
            std::cout << "Enter a number of a command: ";
            std::cin >> command;

            if (command == "1") {
                Journey newJourney;
                char confirm = 'T';
                bool addNewJourney = true;

                myInterface::setJourney(newJourney);
                while(newJourney.getGrade() == 6 || newJourney.getTimePeriod() == "Invalid period" || !newJourney.getDestination().doesContain(',')) {
                    SetConsoleTextAttribute(hConsole, 4);
                    std::cout << "Invalid journey!\n";
                    SetConsoleTextAttribute(hConsole, 7);
                    while (confirm != 'Y' && confirm != 'N' && confirm != 'n' && confirm != 'y') {
                        std::cout << "Add new one (Y/N):";
                        std::cin >> confirm;
                        std::cin.ignore();
                    }
                    if (confirm == 'Y' || confirm == 'y') {
                        newJourney.erasePhotos();
                        myInterface::setJourney(newJourney);
                        confirm = 'T';
                    }
                    else {
                        addNewJourney = false;
                        break;
                    }
                }
                if (addNewJourney) {
                    myInterface::pushJourneyToDB(newJourney, currentUser);
                    SetConsoleTextAttribute(hConsole, 10);
                    std::cout << "Journey successfully added!\n";
                    SetConsoleTextAttribute(hConsole, 7);
                }
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
                    SetConsoleTextAttribute(hConsole, 10);
                    std::cout << "Successfully added!\n";
                    SetConsoleTextAttribute(hConsole, 7);
                }
                else{
                    SetConsoleTextAttribute(hConsole, 4);
                    std::cout << "There is no such user in our system.\n";
                    SetConsoleTextAttribute(hConsole, 7);
                }
//                Vector<User*> u1 = currentUser.getFriends();
//                u1.getSize();
            }
            else if (command == "3") {
                myInterface::showFriends(currentUser);
            }
            else if (command == "4") {
                myInterface::getFriendsReview(currentUser);
            }
            else if (command == "5") {
                myInterface::getGrades(allUsers);
            }
            else if (command == "6") {
                myInterface::getAllDestinations(allUsers);
            }
            else if (command == "7") {
                currentUser.clear();
                isLoggedIn = false;
            }
            else if (command == "8") {
                while (confirmation != 'Y' && confirmation != 'N' && confirmation != 'n' && confirmation != 'y') {
                    std::cout << "Are you sure you want to exit? (Y/N): ";
                    std::cin >> confirmation;
                    std::cin.ignore();
                }
            }
            else {
                SetConsoleTextAttribute(hConsole, 4);
                std::cout << "Invalid command!\n";
                SetConsoleTextAttribute(hConsole, 7);
            }

            if (command == "8" && (confirmation == 'Y' || confirmation == 'y')) {
                break;
            }
            else {
                confirmation = ' ';
            }
        }
        else {
//            std::cout << "11" << "\n";
            myInterface::commands();
//            std::cout << "12" << "\n";
            std::cout << "Enter a number of a command: ";
            std::cin >> command;
            if (command == "1") {
                currentUser = myInterface::logIn(allUsers);

                if(currentUser.getId() != -1) {
                    isLoggedIn = true;
                    SetConsoleTextAttribute(hConsole, 10);
                    std::cout << "Log in successful!\n";
                    SetConsoleTextAttribute(hConsole, 7);
                }
            }
            else if (command == "2") {
                currentUser = myInterface::signUp(currentId);

                if(currentUser.getId() != -1) {
                    currentId++;
                    myInterface::pushUserToDB(currentUser);
                    isLoggedIn = true;
                }
            }
            else if (command == "3") {
//                std::cout << "13" << "\n";
                while (confirmation != 'Y' && confirmation != 'N' && confirmation != 'n' && confirmation != 'y') {
//                    std::cout << "14" << "\n";
                    std::cout << "Are you sure you want to exit? (Y/N): ";
                    std::cin >> confirmation;
                    std::cin.ignore();
                }
            }
            else {
//                std::cout << "15" << "\n";
                SetConsoleTextAttribute(hConsole, 4);
                std::cout << "Invalid command!\n";
                SetConsoleTextAttribute(hConsole, 7);
            }

            if (command == "3" && (confirmation == 'Y' || confirmation == 'y')) {
//                std::cout << "16" << "\n";
                break;
            }
            else {
//                std::cout << "17" << "\n";
                confirmation = ' ';
            }
        }
    }



//    SetConsoleTextAttribute(hConsole, 4);
//    String s1;
//    std::cin >> s1;
//    std::cout <<s1 <<std::endl;


//Journey j;
//interface::setJourney(j);
//j.display();
//j.erasePhotos();
//    interface::setJourney(j);
//    j.display();



//    String s1 = "hasdshasd";
//    std::cout << s1 << std::endl;
//    s1.push_back('5');
//    std::cout << s1 << std::endl;


//    Vector<String> v;
//    v.pushBack("str1");
//    v.pushBack("str2");
//    v.pushBack("str3");
//    v.pushBack("str4");
//    v.pushBack("str5");
//    v.pushBack("str6");
//    v.pushBack("str7");
//    v.pushBack("str8");
//    v.print();
//    std::cout << v.elem("str3") << std::endl;
//    std::cout << v.elem("st1r3") << std::endl;
//    v.eraseData();
//    std::cout << *(v.getData()) << "\n";
//    v.pushBack("str10");
//    std::cout << *(v.getData()) << "\n";

//    v.print();

//int a = 5;
////
//Vector<int> v;
//v.pushBack(a);
//a++;
//v.pushBack(a);
//v.print();
//
//    std::cout << v.elem(4) << std::endl;
//    std::cout << v.elem(5) << std::endl;
    return 0;
}
