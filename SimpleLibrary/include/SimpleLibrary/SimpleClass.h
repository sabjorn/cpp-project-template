#pragma once

/**
    SimpleClass
    A simple class example for building and testing purposes

    Accumulates an input
*/
class SimpleClass {

public:
    SimpleClass();

    void addValue(double in);
    double getValue();

private:
    double bucket_;
};
