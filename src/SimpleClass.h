#pragma once

/**
    SimpleClass
    A simple class example for building and testing purposes

    Accumulates an input
*/
class SimpleClass {

private:
    double bucket; /**< accumulates input */

public:
    SimpleClass();
    ~SimpleClass();

    void addValue(double in);
    double getValue();
};
