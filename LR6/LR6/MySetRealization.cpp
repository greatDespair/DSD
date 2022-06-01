#include "MySet.h";

// Получение указателя на верщину
ElementOOP* MySet::getStart() {
    return start;
}
// Создание пустого множества
MySet::MySet() {
    start = nullptr;
}

MySet::~MySet() {
    //this->deleteSet();
}

// Создание пустого множества
MySet MySet::creatingAnEmptySet() {
    return *new MySet;
}
// Проверка на пустое множество
bool MySet::isEmpty() {
    return start == nullptr;
}
// Проверка принадлежности элемента множеству
bool MySet::SetCheck(int value) {
    if (this->isEmpty()) return false;
    ElementOOP* current = start;
    while (current->Next && current->Value != value)
        current = current->Next;
    return current->Value == value;
}
// Добавление нового элемента в множество в начало списка
void MySet::add(int value) {
    if (!SetCheck(value)) {
        ElementOOP* new_node = new ElementOOP;
        new_node->Value = value;
        new_node->Next = start;
        start = new_node;
    }
}
// Мощность множества
int MySet::SetPower() {
    int power = 0;
    if (this->isEmpty()) return 0;
    ElementOOP* current = start;
    power++;
    while (current->Next) {
        current = current->Next;
        power++;
    }
    return power;
}
// Создание нового множества
void MySet::generateSet(int count, int min, int max, int lastDigit) {
        int i = 0;
        ElementOOP* check;
        if (lastDigit == 3) {
            while (i < count) {
                check = start;
                int temp = rand() % (max - min + 1) + min;
                if (temp % 10 > 3) {
                    add(temp);
                    if (start != check)
                        i++;
                }
            }
        }
        else
            if (lastDigit == 8)
                while (i < count) {
                    check = start;
                    int temp = rand() % (max - min + 1) + min;
                    if (temp % 10 < 8) {
                        add(temp);
                        if (start != check)
                            i++;
                    }
                }
            else
                cout << "Ошибка добавления" << endl;

}
// Вывод элементов множества
string MySet::printSet() {
    if (this->isEmpty()) return "Пустое множество";
    ElementOOP* current = start;
    string print;
    while (current->Next) {
        print += to_string(current->Value) + " ";
        current = current->Next;
    }
    print += to_string(current->Value);
    return print;
}
// Удаление множества
void MySet::deleteSet() {
    ElementOOP* current = start;
    if (this->isEmpty())                   
        cout << "Нет удаляемых элементов множества" << endl;
    while (current) {                       
        ElementOOP* temp = current;
        current = current->Next;
        delete temp;
    }
    start = nullptr;
}
// Является ли A подмножеством B
bool MySet::isSubset(MySet a, MySet b) {
    if (a.isEmpty()) return true;
    if (a.SetPower() > b.SetPower()) return false;
    ElementOOP* current = a.getStart();
    while (current->Next) {
        if (!b.SetCheck(current->Value))
            return false;
        current = current->Next;
    }
    return true;
}
// Проверка множеств на равенство
bool MySet::isEqual(MySet a, MySet b) {
    return isSubset(a, b) && (a.SetPower() == b.SetPower());
}
// Объединение множеств
MySet MySet::mergeSets(MySet a, MySet b) {
    if (a.isEmpty() || b.isEmpty())
        return *new MySet();
    MySet c = a;
    ElementOOP* current = b.getStart();
    while (current->Next) {
        if (!c.SetCheck(current->Value))
            c.add(current->Value);
        current = current->Next;
    }
    if (b.SetCheck(current->Value))
        c.add(current->Value);
    return c;
}
// Пересечение множеств
MySet MySet::sameOfSets(MySet a, MySet b) {
    if (a.isEmpty() || b.isEmpty())
        return *new MySet();
    MySet c = *new MySet();
    ElementOOP* current = a.getStart();
    while (current->Next) {
        if (b.SetCheck(current->Value))
            c.add(current->Value);
        current = current->Next;
    }
    if (b.SetCheck(current->Value))
        c.add(current->Value);
    return c;
}
// Разность множеств
MySet MySet::diffOfSets(MySet a, MySet b) {
    if (a.isEmpty() || b.isEmpty())
        return *new MySet();
    MySet c = *new MySet();
    ElementOOP* current = a.getStart();
    while (current->Next) {
        if (!b.SetCheck(current->Value))
            c.add(current->Value);
        current = current->Next;
    }
    if (!b.SetCheck(current->Value))
        c.add(current->Value);
    return c;
}
// Симметричная разность множеств
MySet MySet::symDiffOfSets(MySet a, MySet b) {
    if (sameOfSets(a, b).isEmpty()) return mergeSets(a, b);
    return diffOfSets(mergeSets(a, b), sameOfSets(a, b));
}
