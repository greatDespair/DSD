#pragma once
#include <list>;
#include <iostream>;
#include <string>;

using namespace std;
class SetList {
private:
	list <int> Set;
public:
	bool isEmpty();
	bool SetCheck(int value);
	void add(int value);
	int SetPower();
	void generateSet(int count, int min, int max, int lastDigit);
	string printSet();
	void deleteSet();
	bool isSubset(SetList SetA, SetList SetB);
	bool isEqual(SetList A, SetList B);

	SetList mergeSets(SetList A, SetList B);

	SetList sameOfSets(SetList A, SetList B);
	SetList diffOfSets(SetList A, SetList B);
	SetList symDiffOfSets(SetList A, SetList B);

};