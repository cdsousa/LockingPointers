#ifndef LOCK_PTR_HPP
#define LOCK_PTR_HPP


#include <shared_mutex>


template <class T> class unique_lock_ptr {
private:
    T* _ptr;
    std::unique_lock<std::shared_timed_mutex> _lock;

public:
    unique_lock_ptr(T* ptr, std::shared_timed_mutex& mtx)
        : _ptr(ptr), _lock(std::unique_lock<std::shared_timed_mutex>(mtx)) {}
    T* operator->() const noexcept { return _ptr; }
    T& operator*() const noexcept { return *_ptr; }
};


template <class T> class shared_lock_ptr {
private:
    const T* _ptr;
    std::shared_lock<std::shared_timed_mutex> _lock;

public:
    shared_lock_ptr(const T* ptr, std::shared_timed_mutex& mtx)
        : _ptr(ptr), _lock(std::shared_lock<std::shared_timed_mutex>(mtx)) {}
    const T* operator->() const noexcept { return _ptr; }
    const T& operator*() const noexcept { return *_ptr; }
};


#endif
