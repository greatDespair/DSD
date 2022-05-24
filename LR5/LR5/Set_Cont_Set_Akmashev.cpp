#include <iostream>;
#include "SetLab5_Akmashev.h";

int main()
{
    setlocale(LC_ALL, "Russian");

    SetSet A = *new SetSet();
    SetSet B = *new SetSet();
    A.generateSet(rand() % 4 + 6, 10, 60, 8);
    B.generateSet(rand() % 4 + 6, 10, 60, 3);

    cout << "��������� �: " << A.printSet() << endl;
    cout << "��������� �: " << B.printSet() << endl;
    if (SetSet().isSubset(A, B)) {
        cout << "��������� � �������� ������������� ��������� �" << endl;
    }
    else
    {
        cout << "��������� � �� �������� ������������� ��������� �" << endl;
    }

    if (SetSet().isSubset(A, A)) {
        cout << "��������� � �������� ������������� ��������� �" << endl;
    }
    else
    {
        cout << "��������� � �� �������� ������������� ��������� �" << endl;
    }

    if (SetSet().isSubset(B, A)) {
        cout << "��������� B �������� ������������� ��������� A" << endl;
    }
    else
    {
        cout << "��������� B �� �������� ������������� ��������� A" << endl;
    }

    cout << "�������� �������� � � �" << endl;
    A.deleteSet();
    B.deleteSet();

    cout << "��������� �: " << A.printSet() << endl;
    cout << "��������� �: " << B.printSet() << endl;

    cout << "��������� �������� � � �" << endl;
    A.generateSet(rand() % 4 + 6, 10, 60, 8);
    B.generateSet(rand() % 4 + 6, 10, 60, 3);
    cout << "��������� �: " << A.printSet() << endl;
    cout << "��������� �: " << B.printSet() << endl;

    cout << "����������� �������� � � � - " << SetSet().mergeSets(A, B).printSet() << endl;
    cout << "����������� �������� � � � - " << SetSet().sameOfSets(A, B).printSet() << endl;
    cout << "�������� �������� � � � - " << SetSet().diffOfSets(A, B).printSet() << endl;
    cout << "�������� �������� � � � - " << SetSet().diffOfSets(B, A).printSet() << endl;
    cout << "������������ �������� �������� � � � - " << SetSet().symDiffOfSets(A, B).printSet() << endl;
}