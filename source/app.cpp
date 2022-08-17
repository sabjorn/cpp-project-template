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

        cout << "gain : " << gain.getValue() << " db: " << db.getValue() << "\n"; // static_cast<Gain>(amp).getValue() << "\n";
    }

    {
        auto db = Db(-6.0);
        auto gain = static_cast<Gain<double>>(db);

        cout << "gain : " << gain.getValue() << " db: " << db.getValue() << "\n"; // static_cast<Gain>(amp).getValue() << "\n";
    }
    return 0;
}
