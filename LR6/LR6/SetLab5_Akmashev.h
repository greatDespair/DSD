#pragma once
#pragma once
#include <set>;
#include <iostream>;
#include <string>;

using namespace std;
class SetSet {
private:
	set <int> Set;
public:
	bool isEmpty();
	bool SetCheck(int value);
	void add(int value);
	int SetPower();
	void generateSet(int count, int min, int max, int lastDigit);
	string printSet();
	void deleteSet();
	bool isSubset(SetSet SetA, SetSet SetB);
	bool isEqual(SetSet A, SetSet B);

	SetSet mergeSets(SetSet A, SetSet B);

	SetSet sameOfSets(SetSet A, SetSet B);
	SetSet diffOfSets(SetSet A, SetSet B);
	SetSet symDiffOfSets(SetSet A, SetSet B);
};