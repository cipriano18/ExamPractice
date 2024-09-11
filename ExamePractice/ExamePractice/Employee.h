#pragma once
#include <iostream>
using namespace std;
class Employee{
private:

	int id;
	int hoursWorked;
	Employee* next;

public:
	Employee();
	Employee(int , int);

	void setId(int);
	void setHoursWorked(int);

	void setNext(Employee* next);

	int getId();
	int getHoursWorked();
	Employee* getNext();

	void insertEmployee(Employee* newEmployee);
	void printEmployee();
	Employee* addEmployee(Employee* head);
    void menu();
};