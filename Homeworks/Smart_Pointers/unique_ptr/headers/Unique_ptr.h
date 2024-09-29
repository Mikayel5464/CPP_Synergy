#ifndef __Unique_ptr_H__
#define __Unique_ptr_H__

template <typename T>
class UniquePtr {
    public:
        explicit UniquePtr(T* ptr = nullptr);
        UniquePtr(UniquePtr&& other) noexcept;
        UniquePtr& operator=(UniquePtr&& other) noexcept;
        UniquePtr(UniquePtr&) = delete;
        UniquePtr& operator=(UniquePtr&) = delete;
        T& operator*() const;
        T* operator->() const;
        T* get() const;
        ~UniquePtr();
    private:
        T* m_ptr;
};

#include "../src/Unique_ptr.cpp"

#endif