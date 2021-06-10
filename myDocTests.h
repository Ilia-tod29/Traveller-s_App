//
// Created by Ilia on 6/7/2021.
//

#ifndef TRAVELLER_S_APP_MYDOCTESTS_H
#define TRAVELLER_S_APP_MYDOCTESTS_H

#define DOCTEST_CONFIG_IMPLEMENT

TEST_CASE("User default constructor test")
{
    User user1;
    CHECK(user1.getId() == -1);
    CHECK(user1.getUsername() == "");
    CHECK(user1.getEMail() == "");
    CHECK(user1.getPassword() == "");
}

TEST_CASE("User setAuth test")
{
    String name = "Ilia", email = "Ilia@abv.bg", password = "00000000";
    User user1;
    user1.setAuth(0, name, password, email);
    CHECK(user1.getId() == 0);
    CHECK(user1.getUsername() == name);
    CHECK(user1.getEMail() == email);
    CHECK(user1.getPassword() == password);
}

TEST_CASE("User friends test")
{
    User user1;
    user1.setAuth(0, "Ilia", "00000000", "Ilia@abv.bg");
    User user2;
    user2.setAuth(1, "Pesho", "88888888", "pesho@gmail.com");
    user1.addFriend(&user2);
    CHECK(user1.getFriends().getSize() == 1);
}

TEST_CASE("Auth default constructor test")
{
    Auth _auth;
    CHECK(_auth.getUsername() == "");
    CHECK(_auth.getPassword() == "");
}

TEST_CASE("User constructor with parameters test")
{
    Auth _auth("Ilia", "Ilia8888");
    CHECK(_auth.getUsername() == "Ilia");
    CHECK(_auth.getPassword() == "Ilia8888");
}

TEST_CASE("Journey setters test")
{
    Journey _journey;
    _journey.setDestination("Pazardzhik, Bulgaria");
    _journey.setTimePeriod("2021-03-23/2021-04-10");
    _journey.setComment("Beautiful & peaceful place");

    _journey.setGrade(5);
    CHECK(_journey.getGrade() == 5);
    _journey.setGrade("4");
    CHECK(_journey.getGrade() == 4);

    _journey.addPhoto("pz.jpeg");
    CHECK(_journey.getPhotos() == "pz.jpeg");
    _journey.erasePhotos();
    CHECK(_journey.getPhotos() == "");


    CHECK(_journey.getDestination() == "Pazardzhik, Bulgaria");
    CHECK(_journey.getTimePeriod() == "2021-03-23/2021-04-10");
    CHECK(_journey.getComment() == "Beautiful & peaceful place");
}

TEST_CASE("String test")
{
    String s1, s2("Valid string"), s3, s4;
    CHECK(s1.getData() == nullptr);
    CHECK(s2 == "Valid string");
    s1 += "This is a string.";
    CHECK(s1 == "This is a string.");
    s1 += "|addition.";
    s3 = s1 + s2;
    CHECK(s1 == "This is a string.|addition.");
    CHECK(s3 == "This is a string.|addition.Valid string");
    CHECK(s3.getExact(10, 15) == "string");
    CHECK(s3.leftPart('|') == "This is a string.");
    CHECK(s3.rightPart('|') == "addition.Valid string");
    CHECK(s3.isEmpty() == false);
    CHECK(s4.isEmpty());
    CHECK(s3[10] == 's');
    CHECK(s3.doesContain('s'));
    s4 = "1954";
    CHECK(s4.toInt() == 1954);
    s2.removeSpaces();
    CHECK(s2 == "Validstring");
    CHECK(s2.length() == 11);
    CHECK(s2 != s3);
}

TEST_CASE("Vector test")
{
    Vector<int> s1;
    s1.pushBack(5);
    s1.pushBack(4);
    s1.pushBack(3);
    CHECK(s1.getSize() == 3);
    CHECK(s1.getCapacity() == 8);
    CHECK(s1[1] == 4);
    s1.popBack();
    s1.popBack();
    CHECK(s1.getSize() == 1);
    CHECK(s1[0] == 5);
    s1.pushBack(4);
    s1.pushBack(3);
    s1.pushBack(4);
    s1.pushBack(3);
    s1.pushBack(4);
    s1.pushBack(3);
    s1.pushBack(4);
    s1.pushBack(3);
    CHECK(s1.getCapacity() == 16);
    CHECK(s1.elem(4));
    CHECK(s1.elem(9) == false);
    s1.eraseData();
    CHECK(s1.getSize() == 0);
    CHECK(s1.getCapacity() == 8);
}
#endif //TRAVELLER_S_APP_MYDOCTESTS_H
