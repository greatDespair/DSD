#include <iostream>;
#include "SetLab4_Akmashev.h";

int main()
{
    setlocale(LC_ALL, "Russian");

    SetList A = *new SetList();
    SetList B = *new SetList();
    A.generateSet(rand() % 4 + 6, 10, 60, 8);
    B.generateSet(rand() % 4 + 6, 10, 60, 3);

    cout << "��������� �: " << A.printSet() << endl;
    cout << "��������� �: " << B.printSet() << endl;
    if (SetList().isSubset(A, B)) {
        cout << "��������� � �������� ������������� ��������� �" << endl;
    }
    else
    {
        cout << "��������� � �� �������� ������������� ��������� �" << endl;
    }

    if (SetList().isSubset(A, A)) {
        cout << "��������� � �������� ������������� ��������� �" << endl;
    }
    else
    {
        cout << "��������� � �� �������� ������������� ��������� �" << endl;
    }

    if (SetList().isSubset(B, A)) {
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

    cout << "����������� �������� � � � - " << SetList().mergeSets(A, B).printSet() << endl;
    cout << "����������� �������� � � � - " << SetList().sameOfSets(A, B).printSet() << endl;
    cout << "�������� �������� � � � - " << SetList().diffOfSets(A, B).printSet() << endl;
    cout << "�������� �������� � � � - " << SetList().diffOfSets(B, A).printSet() << endl;
    cout << "������������ �������� �������� � � � - " << SetList().symDiffOfSets(A, B).printSet() << endl;
}