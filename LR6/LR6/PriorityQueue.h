#pragma once
#pragma once
#include <queue>;
#include <iostream>;
#include <string>;

using namespace std;

class QueueSet {
private:
	priority_queue <int> Set;
public:
	QueueSet();
	bool isEmpty();
	bool SetCheck(int value);
	void add(int value);
	int SetPower();
	void generateSet(int count, int min, int max, int lastDigit);
	string printSet();
	void deleteSet();
	bool isSubset(QueueSet SetA, QueueSet SetB);
	bool isEqual(QueueSet A, QueueSet B);

	QueueSet mergeSets(QueueSet A, QueueSet B);

	QueueSet sameOfSets(QueueSet A, QueueSet B);
	QueueSet diffOfSets(QueueSet A, QueueSet B);
	QueueSet symDiffOfSets(QueueSet A, QueueSet B);
};