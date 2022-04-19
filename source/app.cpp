#include <iostream>

#include <SimpleLibrary/SimpleClass.h>
#include <SimpleLibrary/SimpleStruct.h>

using namespace std;

int main()
{
    SimpleClass accumulator;
    cout << "accumulator value: " << accumulator.getValue() << endl;

    accumulator.addValue(1);
    cout << "accumulator value: " << accumulator.getValue() << endl;

    accumulator.addValue(2);
    cout << "accumulator value: " << accumulator.getValue() << endl;

    auto s = SimpleStruct(0, 0);
    cout << "SimpleStruct values, a: " << s.a << " b: " << s.b << endl;

    return 0;
}
