#include <iostream>
#include <stdlib.h>
#include "Vector.h"
#include "String.h"
#include "Journey.h"
#include "User.h"
#include "Auth.h"
#include "Interface.h"

using namespace interface;
int main() {
//    Vector<int> dynamicArray;
//    dynamicArray.pushBack(5);
//    dynamicArray.pushBack(5);
//    dynamicArray.pushBack(5);
//    dynamicArray.pushBack(5);
//    dynamicArray.pushBack(5);
//    dynamicArray.pushBack(5);
//    dynamicArray.pushBack(5);
//    dynamicArray.pushBack(6);
//    dynamicArray.pushBack(15);
//    dynamicArray.resize(17);
//    dynamicArray.print();
//    std::cout << "size: " << dynamicArray.getSize() << std::endl;
//    std::cout << "Cap: " << dynamicArray.getCapacity() << std::endl;
//
//    Vector<int> dynamicArrayTwo(5, 10);
//    dynamicArrayTwo.print();
//
//    std::cout << "-------------------------------" << std::endl;
//
//    Vector<int> dynamicArrayTwoCopy = dynamicArrayTwo;
//    dynamicArrayTwoCopy.print();
//
//    std::cout << "-------------------------------" << std::endl;
//    dynamicArrayTwoCopy[0] = 2;
//    dynamicArrayTwoCopy.print();
//
//    std::cout << "-------------------------------" << std::endl;
//    dynamicArrayTwo.print();
//
//    std::cout << "-------------------------------" << std::endl;
//    dynamicArrayTwoCopy = Vector<int>(2, 2);
//    dynamicArrayTwoCopy.print();
//    std::cout << "---------------PUSHBACK----------------" << std::endl;
//    dynamicArrayTwoCopy.pushBack(5);
//    dynamicArrayTwoCopy.print();
//    std::cout << "---------------POPBACK----------------" << std::endl;
//    dynamicArrayTwoCopy.popBack();
//    dynamicArrayTwoCopy.print();
//
//
//
//    String str1("9owa e st-/ring.");
//    String str2("A towa e dopylnenieto mu.");
//    String str3;
//    std::cout << str3.length() << std::endl;
//    std::cout << str2.length() << std::endl;
//    std::cout << str3.isEmpty() << std::endl;
//    std::cout << str2.isEmpty() << std::endl;
//
//    str3 = str1 + str2;
////    str1 += str2;
////    str2 = str1;
//    str2 = str1.getExact(1,5);
//
//    std::cout << str3 << std::endl;
//    std::cout << str2 << std::endl;
//    std::cout << str1 << std::endl;
//    std::cout << ((int)str1[0] - 48 + 25) << std::endl;
//    std::cout << str1.leftPart('-').length() << std::endl;
//    std::cout << str1.rightPart('-').length() << std::endl;
//    std::cout << str1.leftPart('-') << std::endl;
//    str1 = str1.rightPart('-');
//    std::cout << str1 << std::endl;
//    std::cout << str1.rightPart('-') << std::endl;
//    std::cout << (str3 == str1) << std::endl;
//    std::cout << "End of string test" << std::endl;
//
    Journey jo;
    jo.setTimePeriod("2019-07-05/2019-07-29");
    jo.setDestination("Burgas, Bulgaria");
    jo.setGrade(5);
    jo.setComment("Perfect place!");
    jo.addPhoto("Argaz.png");
    jo.setAndSeparatePhotos("burgas.jpeg,locumfest.png,sunrise_on_the_coast.jpeg");

    jo.display();

    User ilia, Vili;
    Vili.setAuth(1, "Vili", "Vili123", "Vilia@abv.bg");
    ilia.setAuth(0, "Ilia", "0000ilia6", "ilia8888@abv.bg");
    ilia.setFriend(&Vili);
//    ilia.setJourney(jo);
//    ilia.showFriends();
    Vili.setFriend(&ilia);
//    Vili.showFriends();
//
//    std::cout << Vili.getId() << "\n";
//
//    Vector<User> friendsVisited = Vili.friendsVisitedADestination("Burgas", " Bulgaria");
//    for (int i = 0; i < friendsVisited.getSize(); ++i) {
//        system("Color E4");
//        std::cout << friendsVisited[i].getUsername() << "\n";
//    }
//
    User Georgi;
    Auth a1("Georgi", "0000gosho");
    Georgi = a1.signUp(3, "gosho69@abv.bg");
//
//    std::cout << Georgi.getId() << "\n";
//    std::cout << Georgi.getUsername() << "\n";
//    std::cout << Georgi.getPassword() << "\n";
//    std::cout << Georgi.getEMail() << "\n";
//    for (int i = 0; i < Georgi.getJourneys().getSize(); ++i) {
//        Georgi.getJourneys()[i].display();
//    }
//    Georgi.showFriends();

//    String str, str1;
//    std::cin >> str;
//    std::cin >> str1;
//    std::cout << str << "\n";
//    std::cout << str1 << "\n";
//    std::cout << str.length() << "\n";

//    Vector<User> allUsers;
//    allUsers.pushBack(ilia);
//    allUsers.pushBack(Vili);
//    allUsers.pushBack(Georgi);
//    User newUser = interface::logIn(allUsers);
//    newUser.showFriends();
//
//    User newNewUser = interface::signUp(4);
//    std::cout << newNewUser.getUsername() << " " << newNewUser.getEMail() << "\n";

//    interface::userSetUp(Vili);

//    String s1("zdr, kp");
//    getline(std::cin, s1, ',');
//    std::cout << s1 << "\n";
//    std::cout << s1.length() << "\n";

//    Journey jo1;
//    jo1.setGrade("18");
//    std::cout << jo1.getGrade() <<"\n";



    interface::userSetUp(ilia);
    for (int i = 0; i < ilia.getJourneys().getSize(); ++i) {
        ilia.getJourneys()[i].display();
    }





//    std::ofstream myFile("CSC2134.txt", std::ios_base::app);
//
//    if(myFile.is_open())
//    {
//        std::cout << "wytre si" << std::endl;
//        std::string str;
//        do{
//            getline(std::cin, str);
//            myFile<<str;
//        }while(str!="");
//    }
//    else std::cerr<<"Unable to open file";
//
//    myFile.close();
//    std::ifstream myFile1("CSC2134.txt");
//
//    Vector<std::string> v1;
//    std::string s1;
//    if(myFile1.is_open())
//    {
//        while(!myFile1.eof()){
//            getline(myFile1, s1, '|');
//            v1.pushBack(s1);
//        }
//    }
//    else std::cerr<<"Unable to open file";
//    v1.print();
//    myFile.close();


    return 0;
}
