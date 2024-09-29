#ifndef __Unique_ptr_cpp__
#define __Unique_ptr_cpp__

#include <iostream>
#include "../headers/Unique_ptr.h"

template <typename T>
UniquePtr<T>::UniquePtr(T* ptr) 
    : m_ptr{ptr}
    {
        std::cout << "Constructor" << std::endl;
    }

template <typename T>
UniquePtr<T>::UniquePtr(UniquePtr&& other) noexcept {
    m_ptr = other.m_ptr;

    other.m_ptr = nullptr;

    std::cout << "Move ctor" << std::endl;
}

template <typename T>
UniquePtr<T>& UniquePtr<T>::operator=(UniquePtr&& other) noexcept {
    if (this != &other) {
        delete m_ptr;

        m_ptr = other.m_ptr;
        other.m_ptr = nullptr;
    }

    std::cout << "Move assignment" << std::endl;

    return *this;
}

template <typename T>
T& UniquePtr<T>::operator*() const {
    return *m_ptr;
}

template <typename T>
T* UniquePtr<T>::operator->() const {
    return m_ptr;
}

template <typename T>
T* UniquePtr<T>::get() const {
    return m_ptr;
}

template <typename T>
UniquePtr<T>::~UniquePtr() {
    delete m_ptr;

    std::cout << "Destructor" << std::endl;
}

#endif