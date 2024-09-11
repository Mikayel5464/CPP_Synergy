#include <iostream>
#include "Person.h"

Person::Person() 
    : m_name{""}, 
    m_age{0}, 
    m_car{nullptr} {
    std::cout << "Person default ctor" << std::endl;
}

Person::Person(std::string name, int age) 
    : m_name{name}, 
    m_age{age}, 
    m_car{nullptr}  {
    std::cout << "Person parametrized ctor" << std::endl;
}

Person::Person(const Person& other) {
    m_name = other.m_name;
    m_age = other.m_age;

    if (other.m_car != nullptr) {
        m_car = new Car(*other.m_car);
    } else {
        m_car = nullptr;
    }

    std::cout << "Person copy ctor" << std::endl;
}

Person& Person::operator=(const Person& other) {
    if (this == &other) {
        return *this;
    }

    m_name = other.m_name;
    m_age = other.m_age;

    if (m_car != nullptr) {
        delete m_car;
    }

    if (other.m_car != nullptr) {
         m_car = new Car(*other.m_car);
    } else {
        m_car = nullptr;
    }

    std::cout << "Person copy assignment operator" << std::endl;

    return *this;
}

Person::Person(Person&& other) {
    m_name = std::move(other.m_name);
    m_age = other.m_age;
    m_car = other.m_car;
    other.m_car = nullptr;

    std::cout << "Person move ctor" << std::endl;
}

Person& Person::operator=(Person&& other) {
    if (this == &other) {
        return *this;
    }

    m_name = std::move(other.m_name);
    m_age = other.m_age;

    if (m_car != nullptr) {
        delete m_car;
    }

    m_car = other.m_car;
    other.m_car = nullptr;

    std::cout << "Person move assignment operator" << std::endl;

    return *this;
}

void Person::setName(std::string name) {
    m_name = name;
}

void Person::setAge(int age) {
    m_age = age;
}

std::string Person::getName() const {
    return m_name;
}

int Person::getAge() const {
    return m_age;
}

void Person::assignCar(const std::string car_mark, const std::string car_model, const int car_year) {
    if (m_car != nullptr) {
        delete m_car;
    }

    m_car = new Car(car_mark, car_model, car_year);
}

void Person::describePersonAndCar() const {
    std::cout << "Person: " << m_name << std::endl;
    std::cout << "Age: " << m_age << std::endl;

    if (m_car != nullptr) {
        std::cout << m_name << " owns a car." << std::endl;
        m_car->describeCar();
    } else {
        std::cout << m_name << " does not own a car." << std::endl;
    }
}

Person::~Person() {
    delete m_car;

    std::cout << "Person destructor" << std::endl;
}
