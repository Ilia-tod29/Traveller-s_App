#include <iostream>
#include "Vector.h"
#include "String.h"
int main() {
    Vector<int> dynamicArray;
    dynamicArray.pushBack(5);
    dynamicArray.pushBack(5);
    dynamicArray.pushBack(5);
    dynamicArray.pushBack(5);
    dynamicArray.pushBack(5);
    dynamicArray.pushBack(5);
    dynamicArray.pushBack(5);
    dynamicArray.pushBack(6);
    dynamicArray.pushBack(15);
    dynamicArray.resize(17);
    dynamicArray.print();
    std::cout << "size: " << dynamicArray.getSize() << std::endl;
    std::cout << "Cap: " << dynamicArray.getCapacity() << std::endl;

    Vector<int> dynamicArrayTwo(5, 10);
    dynamicArrayTwo.print();

    std::cout << "-------------------------------" << std::endl;

    Vector<int> dynamicArrayTwoCopy = dynamicArrayTwo;
    dynamicArrayTwoCopy.print();

    std::cout << "-------------------------------" << std::endl;
    dynamicArrayTwoCopy[0] = 2;
    dynamicArrayTwoCopy.print();

    std::cout << "-------------------------------" << std::endl;
    dynamicArrayTwo.print();

    std::cout << "-------------------------------" << std::endl;
    dynamicArrayTwoCopy = Vector<int>(2, 2);
    dynamicArrayTwoCopy.print();
    std::cout << "---------------PUSHBACK----------------" << std::endl;
    dynamicArrayTwoCopy.pushBack(5);
    dynamicArrayTwoCopy.print();
    std::cout << "---------------POPBACK----------------" << std::endl;
    dynamicArrayTwoCopy.popBack();
    dynamicArrayTwoCopy.print();



    String str1("Towa e string.");
    String str2("A towa e dopylnenieto mu.");
    String str3;
    std::cout << str1.length() << std::endl;
    std::cout << str2.length() << std::endl;

    str3 = str1 + str2;
    str1 += str2;
//    str2 = str1;

    std::cout << str3 << std::endl;
    std::cout << str2 << std::endl;
    std::cout << str1 << std::endl;
    std::cout << "End of string test" << std::endl;
    return 0;
}
