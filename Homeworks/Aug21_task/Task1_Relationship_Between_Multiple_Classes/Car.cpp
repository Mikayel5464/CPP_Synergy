#include <iostream>
#include "Car.h"

Car::Car(std::string mark, std::string model, int year) 
    : m_mark{mark},
    m_model{model},
    m_year{year} 
    {
        std::cout << "Car parametrized ctor" << std::endl;
}

Car::Car(const Car& other) 
    : m_mark{other.m_mark},
    m_model{other.m_model},
    m_year{other.m_year}
    {
        std::cout << "Car copy ctor" << std::endl;
}

Car::Car(Car&& other) 
    : m_mark{std::move(other.m_mark)},
    m_model{std::move(other.m_model)},
    m_year{std::move(other.m_year)} 
    {
        std::cout << "Car move ctor" << std::endl;
}

Car& Car::operator=(const Car& other) {
    if (this == &other) {
        return *this;
    }

    m_mark = other.m_mark;
    m_model = other.m_model;
    m_year = other.m_year;

    std::cout << "Car copy assignment operator" << std::endl;

    return *this;
}

Car& Car::operator=(Car&& other) {
    if (this == &other) {
        return *this;
    }

    m_mark = std::move(other.m_mark);
    m_model = std::move(other.m_model);
    m_year = (other.m_year);

    return *this;
}

void Car::setMark(std::string mark) {
    m_mark = mark;
}

void Car::setModel(std::string model) {
    m_model = model;
}

void Car::setYear(int year) {
    m_year = year;
}

std::string Car::getMark() const {
    return m_mark;
}

std::string Car::getModel() const {
    return m_model;
}

int Car::getYear() const {
    return m_year;
}

void Car::describeCar() {
    std::cout << "Car mark: " << m_mark << std::endl;
    std::cout << "Car model: " << m_model << std::endl;
    std::cout << "Car year: " << m_year << std::endl;
}

Car::~Car() {
    std::cout << "Car destructor" << std::endl;
}
