#pragma once

/**
    Struct
*/
template <typename T> 
struct SimpleStruct {
    T a; /**< First member variable. */
    T b; /**< First member variable. */

    SimpleStruct(T a, T b) {
        this->a = a;
        this->b = b;
    }

    /**
        > overload
        Order of markers is important when arranged in a vector
        and operators will help with the operations of ordering.

        Made inline for potential compiler efficiency
    */
    inline bool operator >(const SimpleStruct<T> &s) const {
        if(this->a > s.a && this->b > s.b)
            return true;
        return false;
    }

    /**
        < overload
        See > overload comment for more details
    */
    inline bool operator <(const SimpleStruct<T> &s) const {
        if(this->a < s.a && this->b < s.b)
            return true;
        return false;
    }

    /**
        == overload
        See > overload comment for more details
    */
    inline bool operator ==(const SimpleStruct<T> &s) const {
        if(this->a == s.a && this->b == s.b)
            return true;
        return false;
    }

    /**
        - overload
        See > overload comment for more details
    */
    inline SimpleStruct<T> operator -(const SimpleStruct<T> &s) const {
        return SimpleStruct(this->a - s.a, this->b - s.b);
    }

    /**
        [] overload
        See > overload comment for more details
    */
    inline T operator [](const int index) const {
        if(index == 0)
            return a;
        return  b;
    }
};