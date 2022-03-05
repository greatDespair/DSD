
#include "SetHeader.h"
#include <iostream>

using namespace std;

int main()
{
    setlocale(LC_ALL, "Russian");
    Element* NewSet1 = createEmptySet();
    NewSet1 = generateSet(9, 10, 60, 3);

    Element* NewSet2 = createEmptySet();
    NewSet2 = generateSet(6, 10, 60, 8);



    cout << "Множество А: " << printSet(NewSet1) << endl;
    cout << "Мощность множества А: " << SetPower(NewSet1) << endl;

    cout << "Множество В: " << printSet(NewSet2) << endl;
    cout << "Мощность множества В: " << SetPower(NewSet2) << endl;
    deleteSet(NewSet2);
    cout << "Множество В: " << printSet(NewSet2) << endl;
}

