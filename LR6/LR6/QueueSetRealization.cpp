#include "PriorityQueue.h";
#include <algorithm>

QueueSet::QueueSet() {
    Set = *new priority_queue<int>();
}
// �������� �� ������ ���������
bool QueueSet::isEmpty() {
    return Set.empty();
}
// �������� �������������� �������� ���������
bool QueueSet::SetCheck(int value) {
    QueueSet currentSet = *this;
    if (Set.empty())
        return false;
    while (!currentSet.Set.empty())
    {
        if (currentSet.Set.top() == value)
            break;
        currentSet.Set.pop();
    }
    if (currentSet.Set.empty())
        return false;
    return true;
}
// ���������� ������ �������� � ��������� � ������ ������
void QueueSet::add(int value) {
    if (!SetCheck(value))
        Set.push(value);
}
// �������� ���������
int QueueSet::SetPower() {
    return Set.size();
}
// �������� ������ ���������
void QueueSet::generateSet(int count, int min, int max, int lastDigit) {
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
string QueueSet::printSet() {
    if (isEmpty()) return "������ ���������!";
    string result;
    QueueSet currentSet = *this;
    while (!currentSet.Set.empty())
    {
        result += to_string(currentSet.Set.top()) + " ";
        currentSet.Set.pop();
    }  
    return result;
}
// �������� ���������
void QueueSet::deleteSet() {
    while (!Set.empty())
    {
        Set.pop();
    }
}
// �������� �� A ������������� B
bool QueueSet::isSubset(QueueSet A, QueueSet B) {
    QueueSet currentSetA = A;
    QueueSet currentSetB = B;
    while (!currentSetB.isEmpty())
    {
        if (currentSetA.Set.top() == currentSetB.Set.top()) 
            currentSetA.Set.pop();
        currentSetB.Set.pop();
    }
    if (currentSetA.isEmpty())
        return true;
    return false;
}
// �������� �������� �� ���������
bool QueueSet::isEqual(QueueSet A, QueueSet B) {
    return isSubset(A, B) && (A.SetPower() == B.SetPower());
}
// ����������� ��������
QueueSet QueueSet::mergeSets(QueueSet A, QueueSet B) {
    if (A.isEmpty() || B.isEmpty()) return *new QueueSet();

    QueueSet C = A;
    QueueSet currentSet = B;
    while (!currentSet.Set.empty())
    {
        if (!C.SetCheck(currentSet.Set.top()))
            C.add(currentSet.Set.top());
        currentSet.Set.pop();
    }

    return C;
}
// ����������� ��������
QueueSet QueueSet::sameOfSets(QueueSet A, QueueSet B) {
    if (A.isEmpty() || B.isEmpty()) return *new QueueSet();

    QueueSet C = *new QueueSet();
    QueueSet currentSet = A;
    while (!currentSet.Set.empty())
    {
        if (!B.SetCheck(currentSet.Set.top()))
            C.add(currentSet.Set.top());
        currentSet.Set.pop();
    }
    return C;
}
// �������� ��������
QueueSet QueueSet::diffOfSets(QueueSet A, QueueSet B) {
    QueueSet C = *new QueueSet();
    QueueSet currentSet = A;
    while (!currentSet.Set.empty())
    {
        if (!B.SetCheck(currentSet.Set.top()))
            C.add(currentSet.Set.top());
        currentSet.Set.pop();
    }
    return C;
}
// ������������ �������� ��������
QueueSet QueueSet::symDiffOfSets(QueueSet A, QueueSet B) {
    if (sameOfSets(A, B).isEmpty()) return mergeSets(A, B);

    return diffOfSets(mergeSets(A, B), sameOfSets(A, B));
}
