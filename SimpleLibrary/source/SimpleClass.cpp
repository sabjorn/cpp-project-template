#include "SimpleClass.h"

SimpleClass::SimpleClass() : bucket_(0)
{
}

/**
    addValue
    Adds a double to the accumuator

    \param in - input value to be accumulated
*/
void SimpleClass::addValue(double in){
    bucket_ += in;
}

/**
    getValue
    Returns accumulated value

    \return bucket_ - accumulated value
*/
double SimpleClass::getValue(){
    return bucket_;
}
