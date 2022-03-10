#pragma once
#include <iostream>
#include <string>

struct Element {
	int Value;
	Element* Next;
};

using namespace std;
class MySet {
public:
	Element* start;

	MySet();
	~MySet();

	bool isEmpty();
	bool SetCheck(int value);
	bool add(int value);
	int SetPower();
	void generateSet(int count, int min, int max, int lastDigit);
	string printSet();
	bool isSubset(MySet SetA, MySet SetB);
	bool isEqual(MySet A, MySet B);
	MySet mergeSets(MySet A, MySet B);
	MySet sameOfSets(MySet A, MySet B);

};