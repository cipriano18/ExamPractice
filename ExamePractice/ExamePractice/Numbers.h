#pragma once
#include <iostream>
using namespace std;
class Numbers {
private:
	int number;
	Numbers* next;
public:
	Numbers(int);
	void setNumber(int);
	int getNumber();
	void setNumberNext(Numbers*);
	Numbers* getNext();

	void insertNumbers(Numbers* newNumber);
	void printNumber();
	void removeDuplicates();
	void insertAtPosition(Numbers*& head, int value, int position);
	int totalNodes();
	bool itIsOrdered(Numbers* head);
	void removeMin(Numbers*& head);
	Numbers* intercalateLists(Numbers* list1, Numbers* list2);
};