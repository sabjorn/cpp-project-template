#include <iostream>

#include <SimpleLibrary/SimpleClass.h>
#include <SimpleLibrary/SimpleStruct.h>
#include <SimpleLibrary/Gain.h>

using namespace std;
//using namespace drtl::amplitude;
int main()
{
    {
        auto gain = Gain(2.0);
        auto db = static_cast<Db<double>>(gain);
        auto multiply = gain * db;

        cout << "gain : " << static_cast<double>(gain) << " db: " << static_cast<double>(db) << " multiply: " << static_cast<double>(multiply) << "\n";
        cout << "gain * gain: " << gain * gain << "\n";
    }

    {
        auto db = Db(-6.0);
        auto gain = static_cast<Gain<double>>(db);
        auto multiply = db * gain;

        cout <<  "db: " << static_cast<double>(db) << " gain: " << static_cast<double>(gain) << " multiply: " << static_cast<double>(multiply) << "\n";
        cout << "db * db: " << db * db << "\n";
    }

    return 0;
}
