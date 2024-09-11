#ifndef __Car_H__
#define __Car_H__

#include <iostream>

class Car {
    public:
        Car() = delete;
        Car(std::string, std::string, int);
        Car(const Car&);
        Car(Car&&);
        Car& operator=(const Car&);
        Car& operator=(Car&&);
        ~Car();
        void setMark(std::string);
        void setModel(std::string);
        void setYear(int);
        std::string getMark() const;
        std::string getModel() const;
        int getYear() const;
        void describeCar();
    private:
        std::string m_mark;
        std::string m_model;
        int m_year;
};

#endif