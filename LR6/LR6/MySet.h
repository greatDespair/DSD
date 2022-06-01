#pragma once
#include <iostream>;
#include <string>;


struct ElementOOP {
	int Value;
	ElementOOP* Next;
};

using namespace std;
class MySet {
public:
	ElementOOP* start;

	MySet();
	~MySet();

	ElementOOP* getStart();
	MySet creatingAnEmptySet();
	bool isEmpty();
	bool SetCheck(int value);
	void add(int value);
	int SetPower();
	void generateSet(int count, int min, int max, int lastDigit);
	string printSet();
	void deleteSet();
	bool isSubset(MySet SetA, MySet SetB);
	bool isEqual(MySet A, MySet B);

	MySet mergeSets(MySet A, MySet B);

	MySet sameOfSets(MySet A, MySet B);
	MySet diffOfSets(MySet A, MySet B);
	MySet symDiffOfSets(MySet A, MySet B);

};