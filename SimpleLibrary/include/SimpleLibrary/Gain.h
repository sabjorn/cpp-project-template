#pragma once

#include <cmath>
#include <type_traits>

// forward-declaration
template <typename T, 
          std::enable_if_t<std::is_floating_point<T>::value, bool> = true>
class Db;

template <typename T, 
          std::enable_if_t<std::is_floating_point<T>::value, bool> = true>
class Gain {
    public:
        Gain(T gain) : gain_(gain) {};
        T getValue() { return gain_; };

        operator Db<T>() const 
        { 
            if (gain_ < static_cast<T>(0))
                return Db(static_cast<T>(-150)); 

            return Db(static_cast<T>(20) * std::log10(gain_)); 
        };

    private:
        T gain_;
};

template <typename T, 
          std::enable_if_t<std::is_floating_point<T>::value, bool>>
class Db {
    public:
        Db(T db) : db_(db) {};
        T getValue() const { return db_; };
       
        operator Gain<T>() const 
        { 
            return std::pow(static_cast<T>(10), db_ / static_cast<T>(20));
        };

    private:
        T db_;
};

