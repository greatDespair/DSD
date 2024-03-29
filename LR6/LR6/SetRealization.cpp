#include "SetHeader.h";
#include <iostream>

using namespace std;

//F1 �������� ������� ���������
Element* createEmptySet() {
    Element* first = nullptr;
    return first;
}

//F2 ������ ���������?
bool isEmpty(Element* start) {
    return !start ;
}

//F3 �������� �������������� �������� ���������
bool SetCheck(Element* start, int value) {
    if (isEmpty(start)) return false;
    Element* current = start;
    while (current->next && current->value != value)
        current = current->next;
    return current->value == value;
};

//F4 ���������� ������ �������� � ���������
Element* add(Element*& start, int value) {
    if (!SetCheck(start, value)) {
        Element* new_node = new Element;
        new_node->value = value;
        new_node->next = start;
        start = new_node;
    }
    return start;
}

//F6 �������� ���������
int SetPower(Element* start) {
    int power = 1;
    if (isEmpty(start)) return 0;
    Element* current = start;
    while (current->next) {
        current = current->next;
        power++;
    }
    return power;
}

//F5 �������� ���������
Element* generateSet(int count, int min, int max, int lastDigit) {
    Element* set = createEmptySet();
    int i = 0;
        if (lastDigit == 3) {
            while (i < count) {
                int temp = rand() % (max - min + 1) + min;
                if (temp % 10 > 3)
                {
                    Element* check = set;
                    add(set, temp);
                    if (check != set)
                        i++;
                }
            }
        }
        else
        {
            if (lastDigit == 8)
                while (i < count) {
                    int temp = rand() % (max - min + 1) + min;
                    if (temp % 10 < 8) 
                    {
                        Element* check = set;
                        add(set, temp);
                        if (check != set)
                            i++;
                    }
                }
            else
            {
                cout << "������ ����������" << endl;
                return nullptr;
            }
        }
    return set;
}

//F7 ����� ��������� ���������
string printSet(Element* start) {
    if (isEmpty(start)) return "������ ���������";
    Element* current = start;
    string print;
    while (current->next) {
        print += to_string(current->value) + " ";
        current = current->next;
    }
    print += to_string(current->value);
    return print;
}

//F8 �������� ���������
Element* deleteSet(Element*& start) {
    Element* current = start;
    if (isEmpty(start))               
        cout << "��������� ������!" << endl;
    while (current) {                   
        Element* temp = current;
        current = current->next;
        delete temp;
    }
    start = nullptr;
    return start;
}

//F9 �������������� �-�
bool isSubset(Element* SetA, Element* SetB) {

    if (isEmpty(SetA)) { 
        return true; 
    }

    if (SetPower(SetA) > SetPower(SetB)) { 
        return false; 
    }

    Element* current = SetA;
    while (current->next) {
        if (!SetCheck(SetB, current->value)) {
            return false;
        }
        current = current->next;
    }
    return true;
}

//F10 ��������� ���� ��������
bool isEqual(Element* A, Element* B) {
    return (isSubset(B, A) && isSubset(A, B));
}

//F11 ����������� ���� ��������
Element* mergeSets(Element* A, Element* B) {
    if (isEmpty(A) && isEmpty(B))
        return createEmptySet();
    Element* C = A;
    Element* current = B;
    while (current) 
    {
        if (!SetCheck(C, current->value))
            C = add(C, current->value);
        current = current->next;
    }

    return C;
}

//F12
Element* sameOfSets(Element* A, Element* B) {
    if (isEmpty(A) || isEmpty(B))
        return createEmptySet();

    Element* C = createEmptySet();
    Element* current = A;

    while (current) {
        if (SetCheck(B, current->value))
            C = add(C, current->value);
        current = current->next;
    }

    return C;
}

//F13 �������� ��������
Element* diffOfSets(Element* A, Element* B) {
    if (isEmpty(A) )
        return createEmptySet();

    Element* C = createEmptySet();
    Element* current = A;

    while (current) 
    {
        if (!SetCheck(B, current->value))
            C = add(C, current->value);
        current = current->next;
    }

    return C;
}

//F14 ������������ �������� ��������
Element* symDiffOfSets(Element* A, Element* B) {
    return diffOfSets(mergeSets(A, B), sameOfSets(A, B));
}