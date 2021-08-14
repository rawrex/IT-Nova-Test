#ifndef SINGLETON_H
#define SINGLETON_H

#include <memory>

// A template used to provide thread-safe (due to local static variable)
// Singleton instantiation for needed class
//
// Note the use of the token struct 
// So to avoid complications of friend declarations

template<typename T> class Singleton {
protected:
	// The token is used to avoid befriending the needed classes
    struct token {};
    Singleton() {}
public:
    static T& instance();
    Singleton(const Singleton&) = delete;
    Singleton& operator= (const Singleton) = delete;
};

template<typename T> T& Singleton<T>::instance() {
	// Thread-safe local static
    static const std::unique_ptr<T> instance{new T{token{}}};
    return *instance;
}

#endif
