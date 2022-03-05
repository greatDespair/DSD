#pragma once
#include <string>

struct  Element
{
	int value;
	Element* next;
};

using namespace std;
//F1 Создание пустого множества
Element* createEmptySet();
//F2 Пустое множество?
bool isEmpty(Element* start);
//F3 Проверка принадлежности элемента множеству
bool SetCheck(Element* start, int value);
//F4 Добавление нового элемента в множество
Element* add(Element*& start, int value);
//F6 Мощность множества
int SetPower(Element* start);
//F5 Создание множества
Element* generateSet(int count, int min, int max, int lastDigit);
//F7 Вывод элементов множества
string printSet(Element* start);
//F8 Удаление множества
Element* deleteSet(Element*& start);

//F9 Подможножество А-В
bool isSubset(Element* A, Element* B);
//F10 Равенство двух множеств
bool isEqual(Element* A, Element* B);
//F11 Объединение двух множеств
Element* mergeSets(Element* A, Element* B);