#include <iostream>;
#include "SetLab4_Akmashev.h";

int main()
{
    setlocale(LC_ALL, "Russian");

    SetList A = *new SetList();
    SetList B = *new SetList();
    A.generateSet(rand() % 4 + 6, 10, 60, 8);
    B.generateSet(rand() % 4 + 6, 10, 60, 3);

    cout << "Множество А: " << A.printSet() << endl;
    cout << "Множество В: " << B.printSet() << endl;
    if (SetList().isSubset(A, B)) {
        cout << "Множество А является подмножеством множества В" << endl;
    }
    else
    {
        cout << "Множество А не является подмножеством множества В" << endl;
    }

    if (SetList().isSubset(A, A)) {
        cout << "Множество А является подмножеством множества А" << endl;
    }
    else
    {
        cout << "Множество А не является подмножеством множества А" << endl;
    }

    if (SetList().isSubset(B, A)) {
        cout << "Множество B является подмножеством множества A" << endl;
    }
    else
    {
        cout << "Множество B не является подмножеством множества A" << endl;
    }

    cout << "Удаление множеств А и В" << endl;
    A.deleteSet();
    B.deleteSet();

    cout << "Множество А: " << A.printSet() << endl;
    cout << "Множество В: " << B.printSet() << endl;

    cout << "Генерация множеств А и В" << endl;
    A.generateSet(rand() % 4 + 6, 10, 60, 8);
    B.generateSet(rand() % 4 + 6, 10, 60, 3);
    cout << "Множество А: " << A.printSet() << endl;
    cout << "Множество В: " << B.printSet() << endl;

    cout << "Объединение множеств А и В - " << SetList().mergeSets(A, B).printSet() << endl;
    cout << "Пересечение множеств А и В - " << SetList().sameOfSets(A, B).printSet() << endl;
    cout << "Разность множеств А и В - " << SetList().diffOfSets(A, B).printSet() << endl;
    cout << "Разность множеств В и А - " << SetList().diffOfSets(B, A).printSet() << endl;
    cout << "Симметричная разность множеств А и В - " << SetList().symDiffOfSets(A, B).printSet() << endl;
}