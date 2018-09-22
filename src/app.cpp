#include <iostream>
#include "SimpleClass.h"
#include "SimpleStruct.h"

using namespace std;

int main()
{
    SimpleClass accumulator;
    cout << "accumulator value: " << accumulator.getValue() << endl;

    accumulator.addValue(1);
    cout << "accumulator value: " << accumulator.getValue() << endl;

    accumulator.addValue(2);
    cout << "accumulator value: " << accumulator.getValue() << endl;

    SimpleStruct<double> s = SimpleStruct<double>(0, 0);
    cout << "SimpleStruct values, a: " << s.a << " b: " << s.b << endl;

    return 0;
}
