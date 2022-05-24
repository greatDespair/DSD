#include "SetLab5_Akmashev.h";
#include <algorithm>
// �������� �� ������ ���������
bool SetSet::isEmpty() {
    return Set.empty();
}
// �������� �������������� �������� ���������
bool SetSet::SetCheck(int value) {
    return Set.find(value) != Set.end();
}
// ���������� ������ �������� � ��������� � ������ ������
void SetSet::add(int value) {
    if (!SetCheck(value))
        Set.insert(Set.begin(), value);
}
// �������� ���������
int SetSet::SetPower() {
    return Set.size();
}
// �������� ������ ���������
void SetSet::generateSet(int count, int min, int max, int lastDigit) {
    if (lastDigit == 3) {
        while (Set.size() < count) {
            int temp = rand() % (max - min + 1) + min;
            if (temp % 10 > 3) {
                add(temp);
            }
        }
    }
    else
        if (lastDigit == 8)
            while (Set.size() < count) {
                int temp = rand() % (max - min + 1) + min;
                if (temp % 10 < 8) {
                    add(temp);
                }
            }
        else
            cout << "������ ����������" << endl;
}
// ����� ��������� ���������
string SetSet::printSet() {
    if (isEmpty()) return "������ ���������!";
    string result;
    for (int var : Set)
        result += to_string(var) + " ";
    return result;
}
// �������� ���������
void SetSet::deleteSet() {
    Set.clear();
}
// �������� �� A ������������� B
bool SetSet::isSubset(SetSet A, SetSet B) {
    return includes(A.Set.begin(), A.Set.end(), B.Set.begin(), B.Set.end());
}
// �������� �������� �� ���������
bool SetSet::isEqual(SetSet A, SetSet B) {
    return isSubset(A, B) && (A.SetPower() == B.SetPower());
}
// ����������� ��������
SetSet SetSet::mergeSets(SetSet A, SetSet B) {
    if (A.isEmpty() || B.isEmpty()) return *new SetSet();

    SetSet C = A;
    for (int var : B.Set)
        if (!C.SetCheck(var))
            C.add(var);
    return C;
}
// ����������� ��������
SetSet SetSet::sameOfSets(SetSet A, SetSet B) {
    if (A.isEmpty() || B.isEmpty()) return *new SetSet();

    SetSet C = *new SetSet();
    for (int var : A.Set)
        if (B.SetCheck(var))
            C.add(var);
    return C;
}
// �������� ��������
SetSet SetSet::diffOfSets(SetSet A, SetSet B) {
    SetSet C = *new SetSet();

    for (int var : A.Set)
        if (!B.SetCheck(var))
            C.add(var);
    return C;
}
// ������������ �������� ��������
SetSet SetSet::symDiffOfSets(SetSet A, SetSet B) {
    if (sameOfSets(A, B).isEmpty()) return mergeSets(A, B);

    return diffOfSets(mergeSets(A, B), sameOfSets(A, B));
}
