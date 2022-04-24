#include <iostream>;
#include "MySet.h";


int main()
{
    setlocale(LC_ALL, "Russian");
    //F5--------------------------------------------------------------------
    cout << "<F5>" << endl;
    MySet A = MySet();
    MySet B = MySet();
    A.generateSet(rand() % 4 + 6, 10, 60, 8);
    B.generateSet(rand() % 4 + 6, 10, 60, 3);

    cout << "Множество А: " << A.printSet() << endl;
    cout << "Множество В: " << B.printSet() << endl;

    //F6--------------------------------------------------------------------
    cout << "<F6>" << endl;
    cout << "Мощность множества А - " << A.SetPower() << endl;
    cout << "Мощность множества B - " << B.SetPower() << endl;
    //F9--------------------------------------------------------------------
    cout << "<F9>" << endl;
    if (MySet().isSubset(A, B)) {
        cout << "Множество А является подмножеством множества В" << endl;
    }
    else
    {
        cout << "Множество А не является подмножеством множества В" << endl;
    }

    A.add(7);

    if (MySet().isSubset(A, B)) {
        cout << "Множество А является подмножеством множества В" << endl;
    }
    else
    {
        cout << "Множество А не является подмножеством множества В" << endl;
    }

    if (MySet().isSubset(A, A)) {
        cout << "Множество А является подмножеством множества А" << endl;
    }
    else
    {
        cout << "Множество А не является подмножеством множества А" << endl;
    }

}
