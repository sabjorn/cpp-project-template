#include "SimpleClass.h"

using namespace std;

SimpleClass::SimpleClass()
{
    this->bucket = 0; // initialize members
}

SimpleClass::~SimpleClass()
{

}

/**
    addValue
    Adds a double to the accumuator

    \param in - input value to be accumulated
*/
void SimpleClass::addValue(double in){
    bucket += in;
}

/**
    getValue
    Returns accumulated value

    \return bucket - accumulated value
*/
double SimpleClass::getValue(){
    return bucket;
}