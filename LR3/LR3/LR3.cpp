#include <iostream>;
#include "MySet.h";


int main()
{
    setlocale(LC_ALL, "Russian");

    MySet A = MySet();
    MySet B = MySet();
    A.generateSet(rand() % 4 + 6, 10, 60, 8);
    B.generateSet(rand() % 4 + 6, 10, 60, 3);

    cout << "Множество А: " << A.printSet() << endl;
    cout << "Множество В: " << B.printSet() << endl;

    //F6--------------------------------------------------------------------
    cout << "Мощность множества А - " << A.SetPower() << endl;
    cout << "Мощность множества B - " << B.SetPower() << endl;
    //F9--------------------------------------------------------------------
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

    if (MySet().isSubset(B, A)){
        cout << "Множество B является подмножеством множества A" << endl;
    }
    else
    {
        cout << "Множество B не является подмножеством множества A" << endl;
    }

    cout << "Удаление множеств А и В"<< endl;
    A.deleteSet();
    B.deleteSet();

    cout << "Множество А: " << A.printSet() << endl;
    cout << "Множество В: " << B.printSet() << endl;

    cout << "Генерация множеств А и В" << endl;
    A.generateSet(rand() % 4 + 6, 10, 60, 8);
    B.generateSet(rand() % 4 + 6, 10, 60, 3);
    cout << "Множество А: " << A.printSet() << endl;
    cout << "Множество В: " << B.printSet() << endl;

    cout << "Объединение множеств А и В - " << MySet().mergeSets(A, B).printSet() << endl;
    cout << "Пересечение множеств А и В - " << MySet().sameOfSets(A, B).printSet() << endl;
    cout << "Разность множеств А и В - " << MySet().diffOfSets(A, B).printSet() << endl;
    cout << "Разность множеств В и А - " << MySet().diffOfSets(B, A).printSet() << endl;
    cout << "Симметричная разность множеств А и В - " << MySet().symDiffOfSets(A, B).printSet() << endl;


}
