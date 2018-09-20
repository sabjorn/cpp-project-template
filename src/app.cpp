#include <iostream>
#include "SimpleClass.h"

using namespace std;

int main()
{
    SimpleClass accumulator;
    cout << "accumulator value: " << accumulator.getValue() << endl;

    accumulator.addValue(1);
    cout << "accumulator value: " << accumulator.getValue() << endl;

    accumulator.addValue(2);
    cout << "accumulator value: " << accumulator.getValue() << endl;

    return 0;
}
