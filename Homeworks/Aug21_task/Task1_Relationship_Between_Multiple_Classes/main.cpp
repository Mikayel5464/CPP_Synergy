#include <iostream>
#include "Car.h"
#include "Person.h"

int main() {
    Person person1("David", 24);
    person1.assignCar("BMW", "X5", 2018);
    person1.describePersonAndCar();

    std::cout << "----------------" << std::endl;

    Person person2 = person1; // calling copy ctor
    person2.describePersonAndCar();

    std::cout << "----------------" << std::endl;

    Person person3("Bob", 35);
    person3 = person2; // calling copy assignment operator
    person3.describePersonAndCar();

    std::cout << "----------------" << std::endl;

    Person person4 = std::move(person3); // calling move ctor
    person4.describePersonAndCar();

    std::cout << "----------------" << std::endl;

    Person person5("Alice", 26);
    person5 = std::move(person4); // calling move assignment operator
    person5.describePersonAndCar();

    return 0;
}