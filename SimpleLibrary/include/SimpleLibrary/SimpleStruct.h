#pragma once
#include <stdexcept>
/**
    Struct
*/
template <typename T> 
struct SimpleStruct {
    T a;
    T b;

    SimpleStruct(T a, T b)
    : a(a)
    , b(b)
    {
    }

    /**
        > overload
        Order of markers is important when arranged in a vector
        and operators will help with the operations of ordering.

        Made inline for potential compiler efficiency
    */
    inline bool operator >(const SimpleStruct<T> &s) const {
        if(a > s.a && b > s.b)
            return true;
        return false;
    }

    /**
        < overload
        See > overload comment for more details
    */
    inline bool operator <(const SimpleStruct<T> &s) const {
        if(a < s.a && b < s.b)
            return true;
        return false;
    }

    /**
        == overload
        See > overload comment for more details
    */
    inline bool operator ==(const SimpleStruct<T> &s) const {
        if(a == s.a && b == s.b)
            return true;
        return false;
    }

    /**
        - overload
        See > overload comment for more details
    */
    inline SimpleStruct<T> operator -(const SimpleStruct<T> &s) const {
        return SimpleStruct(a - s.a, b - s.b);
    }

    /**
        [] overload
        See > overload comment for more details
    */
    inline T operator [](const int index) const {
        //defining the exception (why don't use "try"?)
        if (index > 1 || index < 0) { 
            throw std::out_of_range("Index out of range");
        }
        else if(index == 0)
            return a;
        return  b;
    }
};
