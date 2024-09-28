#ifndef __Auto_ptr_cpp__
#define __Auto_ptr_cpp__

#include <iostream>
#include "../headers/Auto_ptr.h"

template <typename T>
AutoPtr<T>::AutoPtr(T* ptr)
    : m_ptr{ptr}
    {}

template <typename T>
AutoPtr<T>::AutoPtr(AutoPtr& other) {
    m_ptr = other.m_ptr;

    other.m_ptr = nullptr;
}

template <typename T>
AutoPtr<T>& AutoPtr<T>::operator=(AutoPtr& other) {
    if (this != &other) {
        delete m_ptr;

        m_ptr = other.m_ptr;
        other.m_ptr = nullptr;
    }

    return *this;
}

template <typename T>
T& AutoPtr<T>::operator*() const {
    return *m_ptr;
}

template <typename T>
T* AutoPtr<T>::operator->() const {
    return m_ptr;
}

template <typename T>
AutoPtr<T>::~AutoPtr() {
    if (m_ptr) {
        delete m_ptr;
        m_ptr = nullptr;
    }
}

#endif
