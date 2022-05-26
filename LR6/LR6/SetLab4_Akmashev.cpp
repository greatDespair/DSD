#include "SetLab4_Akmashev.h";

// Проверка на пустое множество
bool SetList::isEmpty() {
	return Set.empty();
}
// Проверка принадлежности элемента множеству
bool SetList::SetCheck(int value) {
    if (isEmpty()) return false;
    for (int var : Set)
        if (var == value)
            return true;
    return false;
}
// Добавление нового элемента в множество в начало списка
void SetList::add(int value) {
    if (!SetCheck(value))
        Set.push_front(value);
}
// Мощность множества
int SetList::SetPower() {
    return Set.size();
}
// Создание нового множества
void SetList::generateSet(int count, int min, int max, int lastDigit) {
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
string SetList::printSet() {
    if (isEmpty()) return "Пустое множество!";
    string result;
    for (int var: Set)
        result += to_string(var) + " ";
    return result;
}
// Удаление множества
void SetList::deleteSet() {
    Set.clear();
}
// Является ли A подмножеством B
bool SetList::isSubset(SetList A, SetList B) {
    if (A.isEmpty()) return true;
    if (A.SetPower() > B.SetPower()) return false;

    for (int var : A.Set)
        if (!B.SetCheck(var))
            return false;
    return true;
}
// Проверка множеств на равенство
bool SetList::isEqual(SetList A, SetList B) {
    return isSubset(A, B) && (A.SetPower() == B.SetPower());
}
// Объединение множеств
SetList SetList::mergeSets(SetList A, SetList B) {
    if (A.isEmpty() || B.isEmpty()) return *new SetList();

    SetList C = A;
    for (int var : B.Set)
        if (!C.SetCheck(var))
            C.add(var);
    return C;
}
// Пересечение множеств
SetList SetList::sameOfSets(SetList A, SetList B) {
    if (A.isEmpty() || B.isEmpty()) return *new SetList();

    SetList C = *new SetList();
    for (int var : A.Set)
        if (B.SetCheck(var))
            C.add(var);
    return C;
}
// Разность множеств
SetList SetList::diffOfSets(SetList A, SetList B) {
    SetList C = *new SetList();

    for (int var : A.Set)
        if (!B.SetCheck(var))
            C.add(var);
    return C;
}
// Симметричная разность множеств
SetList SetList::symDiffOfSets(SetList A, SetList B) {
    if (sameOfSets(A, B).isEmpty()) return mergeSets(A, B);

    return diffOfSets(mergeSets(A, B), sameOfSets(A, B));
}
