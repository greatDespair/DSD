#pragma once
#include <string>

struct  Element
{
	int value;
	Element* next;
};

using namespace std;
//F1 �������� ������� ���������
Element* createEmptySet();
//F2 ������ ���������?
bool isEmpty(Element* start);
//F3 �������� �������������� �������� ���������
bool SetCheck(Element* start, int value);
//F4 ���������� ������ �������� � ���������
Element* add(Element*& start, int value);
//F6 �������� ���������
int SetPower(Element* start);
//F5 �������� ���������
Element* generateSet(int count, int min, int max, int lastDigit);
//F7 ����� ��������� ���������
string printSet(Element* start);
//F8 �������� ���������
Element* deleteSet(Element*& start);

//F9 �������������� �-�
bool isSubset(Element* A, Element* B);
//F10 ��������� ���� ��������
bool isEqual(Element* A, Element* B);
//F11 ����������� ���� ��������
Element* mergeSets(Element* A, Element* B);