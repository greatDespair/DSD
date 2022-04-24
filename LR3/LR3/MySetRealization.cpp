#include "MySet.h";

MySet::MySet() {
	start.Value = NULL;
    start.Next = nullptr;
}

MySet::~MySet() {
    Element* current = &start;
    if (isEmpty())
        cout << "Множество пустое!" << endl;
    while (current) {
        Element* temp = current;
        current = current->Next;
        delete temp;
    }
    delete &start;
}

bool MySet::isEmpty() {
    return !&start;
}

bool MySet::SetCheck(int value) {
    if (isEmpty()) 
        return false;
    Element* current = &start;
    while (current) {
        if (current->Value == value)
            return true;
        current = current->Next;
    }
    return false;
}

bool MySet::add(int value) {
    if (!SetCheck(value)) {
        
        Element* new_node = new Element;
        new_node->Value = start.Value;
        new_node->Next = start.Next;
        start.Value = value;
        start.Next = new_node;
        return true;
    }
    return false;
}

int MySet::SetPower() {
    int power = 1;
    if (isEmpty()) return 0;
    Element* current = &start;
    while (current->Next) {
        current = current->Next;
        power++;
    }
    return power;
}

void MySet::generateSet(int count, int min, int max, int lastDigit) {

    int i = 0;

    if (lastDigit == 3) {
        while (i < count) {
            int temp = rand() % (max - min + 1) + min;
            if (temp % 10 > 3)
                if (add(temp))
                    i++;
        }
    }
    else
        if (lastDigit == 8)
            while (i < count) {
                int temp = rand() % (max - min + 1) + min;
                if (temp % 10 < 8)
                    if (add(temp))
                        i++;
            }
        else
            cout << "Ошибка добавления" << endl;
}

string MySet::printSet() {
    if (isEmpty()) return "Пустое множество";
    Element* current = &start;
    string print;
    while (current) {
        print += to_string(current->Value) + " ";
        current = current->Next;
    }
    return print;
}

bool MySet::isSubset(MySet SetA, MySet SetB) {
    cout << "Множество А: " << SetA.printSet() << endl;
    cout << "Множество В: " << SetB.printSet() << endl;

    if (SetA.isEmpty()) {
        return false;
    }

    if (SetA.SetPower() > SetB.SetPower()) {
        return false;
    }

    Element* current = &SetA.start;
    while (current->Next) {
        if (!SetB.SetCheck(current->Value)) {
            return false;
        }
        current = current->Next;
    }
    return true;
}

bool MySet::isEqual(MySet A, MySet B) {
    return isSubset(A, B) && isSubset(B, A);
}

MySet MySet::mergeSets(MySet A, MySet B) {
    if (A.isEmpty() || B.isEmpty())
        return MySet();
    MySet C = MySet();
    Element* current = &A.start;
    while (current)
    {
        C.add(current->Value);
        current = current->Next;
    }

    current = &B.start;
    while (current)
    {
        if (!C.SetCheck(current->Value)) {
            C.add(current->Value);
        }
        current = current->Next;
    }

    return C;
}

MySet MySet::sameOfSets(MySet A, MySet B){
    if (A.isEmpty() || B.isEmpty())
        return MySet();

    MySet C = MySet();
    Element* current = &A.start;

    while (current) {
        if (B.SetCheck(current->Value))
            C.add(current->Value);
        current = current->Next;
    }

    return C;
}

MySet MySet::diffOfSets(MySet A, MySet B) {
    if (A.isEmpty() || B.isEmpty())
        return MySet();

    MySet C = MySet();
    Element* current = &A.start;

    while (current)
    {
        if (!B.SetCheck(current->Value))
            C.add(current->Value);
        current = current->Next;
    }

    return C;
}

MySet MySet::symDiffOfSets(MySet A, MySet B) {

    if (sameOfSets(A, B).isEmpty())
        return mergeSets(A, B);

    return diffOfSets(mergeSets(A, B), sameOfSets(A, B));
}

