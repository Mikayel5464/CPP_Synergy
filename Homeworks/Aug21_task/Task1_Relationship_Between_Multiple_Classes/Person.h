#ifndef __Person_H__
#define __Person_H__

#include <iostream>
#include "Car.h"

class Person {
    public:
        Person();
        Person(std::string, int);
        Person(const Person&);
        Person& operator=(const Person&);
        Person(Person&&);
        Person& operator=(Person&&);
        ~Person();
        void setName(std::string);
        void setAge(int);
        std::string getName() const;
        int getAge() const;
        void assignCar(const std::string, const std::string, const int);
        void describePersonAndCar() const;
    private:
        std::string m_name;
        int m_age;
        Car *m_car;
};

#endif