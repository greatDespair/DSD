#include "SetLab5_Akmashev.h";
#include <algorithm>
// Проверка на пустое множество
bool SetSet::isEmpty() {
    return Set.empty();
}
// Проверка принадлежности элемента множеству
bool SetSet::SetCheck(int value) {
    return Set.find(value) != Set.end();
}
// Добавление нового элемента в множество в начало списка
void SetSet::add(int value) {
    if (!SetCheck(value))
        Set.insert(Set.begin(), value);
}
// Мощность множества
int SetSet::SetPower() {
    return Set.size();
}
// Создание нового множества
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
            cout << "Ошибка добавления" << endl;
}
// Вывод элементов множества
string SetSet::printSet() {
    if (isEmpty()) return "Пустое множество!";
    string result;
    for (int var : Set)
        result += to_string(var) + " ";
    return result;
}
// Удаление множества
void SetSet::deleteSet() {
    Set.clear();
}
// Является ли A подмножеством B
bool SetSet::isSubset(SetSet A, SetSet B) {
    return includes(A.Set.begin(), A.Set.end(), B.Set.begin(), B.Set.end());
}
// Проверка множеств на равенство
bool SetSet::isEqual(SetSet A, SetSet B) {
    return isSubset(A, B) && (A.SetPower() == B.SetPower());
}
// Объединение множеств
SetSet SetSet::mergeSets(SetSet A, SetSet B) {
    if (A.isEmpty() || B.isEmpty()) return *new SetSet();

    SetSet C = A;
    for (int var : B.Set)
        if (!C.SetCheck(var))
            C.add(var);
    return C;
}
// Пересечение множеств
SetSet SetSet::sameOfSets(SetSet A, SetSet B) {
    if (A.isEmpty() || B.isEmpty()) return *new SetSet();

    SetSet C = *new SetSet();
    for (int var : A.Set)
        if (B.SetCheck(var))
            C.add(var);
    return C;
}
// Разность множеств
SetSet SetSet::diffOfSets(SetSet A, SetSet B) {
    SetSet C = *new SetSet();

    for (int var : A.Set)
        if (!B.SetCheck(var))
            C.add(var);
    return C;
}
// Симметричная разность множеств
SetSet SetSet::symDiffOfSets(SetSet A, SetSet B) {
    if (sameOfSets(A, B).isEmpty()) return mergeSets(A, B);

    return diffOfSets(mergeSets(A, B), sameOfSets(A, B));
}
