#ifndef __Auto_Ptr_H__
#define __Auto_Ptr_H__

template <typename T>
class AutoPtr {
    public:
        explicit AutoPtr(T* ptr = nullptr);
        AutoPtr(AutoPtr& other);
        AutoPtr& operator=(AutoPtr& other);
        T& operator*() const;
        T* operator->() const;
        ~AutoPtr();

    private:
        T* m_ptr;
};

#include "../src/Auto_ptr.cpp"

#endif