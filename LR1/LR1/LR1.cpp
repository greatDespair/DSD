
#include "SetHeader.h"
#include <iostream>

using namespace std;

int main()
{
    setlocale(LC_ALL, "Russian");
    Element* NewSet1 = createEmptySet();
    add(NewSet1, 14);
    add(NewSet1, 5);
    add(NewSet1, 56);


    Element* NewSet2 = createEmptySet();
    add(NewSet2, 42);
    add(NewSet2, 60);
    add(NewSet2, 23);
    add(NewSet2, 14);
    add(NewSet2, 5);
    add(NewSet2, 56);

    cout << "Множество А: " << printSet(NewSet1) << endl;
    cout << "Множество В: " << printSet(NewSet2) << endl;
    //F9--------------------------------------------------------------------
    cout << "<F9>" << endl;
    if (isSubset(NewSet1, NewSet2)) {
        cout << "Множество А является подмножеством множества В" << endl;
    }
    else
    {
        cout << "Множество А не является подмножеством множества В" << endl;
    }

    add(NewSet1, 7);

    if (isSubset(NewSet1, NewSet2)) {
        cout << "Множество А является подмножеством множества В" << endl;
    }
    else
    {
        cout << "Множество А не является подмножеством множества В" << endl;
    }

    //F10--------------------------------------------------------------------
    cout << "<F10>" << endl;
    deleteSet(NewSet1);
    deleteSet(NewSet2);
    
    add(NewSet1, 21);
    add(NewSet2, 21);
    if (isEqual(NewSet1, NewSet2)) {
        cout << "Множество А равно множеству В" << endl;
    }
    else {
        cout << "Множество А не равно множеству В" << endl;
    }

    add(NewSet1, 27);

    cout << "Множество А: " << printSet(NewSet1) << endl;
    cout << "Множество В: " << printSet(NewSet2) << endl;

    if (isEqual(NewSet1, NewSet2)) {
        cout << "Множество А равно множеству В" << endl;
    }
    else {
        cout << "Множество А не равно множеству В" << endl;
    }

    //F11--------------------------------------------------------------------
    cout << "<F11>" << endl;
    deleteSet(NewSet1);
    deleteSet(NewSet2);

    NewSet1 = generateSet(5, 10, 60, 3);
    NewSet2 = generateSet(8, 10, 60, 8);

    cout << "Множество А: " << printSet(NewSet1) << endl;
    cout << "Множество В: " << printSet(NewSet2) << endl;

    Element* NewMergedSet = createEmptySet();
    NewMergedSet = mergeSets(NewSet1, NewSet2);

    cout << "Множество C: " << printSet(NewMergedSet) << endl;

    //F12--------------------------------------------------------------------
    cout << "<F12>" << endl;
    deleteSet(NewSet1);
    deleteSet(NewSet2);

    add(NewSet1, 14);
    add(NewSet1, 5);
    add(NewSet1, 56);
    add(NewSet1, 58);

    add(NewSet2, 42);
    add(NewSet2, 60);
    add(NewSet2, 26);
    add(NewSet2, 14);
    add(NewSet2, 5);
    add(NewSet2, 56);
   
    cout << "Множество А: " << printSet(NewSet1) << endl;
    cout << "Множество В: " << printSet(NewSet2) << endl;
    cout << "Пересечение множеств А и В: " << printSet(sameOfSets(NewSet1, NewSet2)) << endl;

    
    //F13--------------------------------------------------------------------
    cout << "<F13>" << endl;
    cout << "Разность множеств А и В: " << printSet(diffOfSets(NewSet1, NewSet2)) << endl;

    //F14--------------------------------------------------------------------
    cout << "<F14>" << endl;
    cout << "Симметричная разность множеств А и В: " << printSet(symDiffOfSets(NewSet1, NewSet2)) << endl;
}

