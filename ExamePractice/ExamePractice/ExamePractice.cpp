#include "iostream"
#include "Employee.h"
#include "Numbers.h"
int main() {

     Employee employeeMenu;
     employeeMenu.menu();

    Numbers* list1 = new Numbers(1);
    list1->insertNumbers(new Numbers(3));
    list1->insertNumbers(new Numbers(5));
    list1->insertNumbers(new Numbers(7));

    Numbers* list2 = new Numbers(2);
    list2->insertNumbers(new Numbers(4));
    list2->insertNumbers(new Numbers(6));
    list2->insertNumbers(new Numbers(8));

    std::cout << "Lista 1 original: " << std::endl;
    list1->printNumber();
    std::cout << "Lista 2 original: " << std::endl;
    list2->printNumber();

    Numbers* head = new Numbers(1);

    head = head->intercalateLists(list1, list2);

    std::cout << "Lista intercalada: " << std::endl;
    head->printNumber();

    if (head->itIsOrdered(head)) {
        std::cout << "Lista ordenada" << std::endl;
    }
    else {
        std::cout << "Lista no ordenada" << std::endl;
    }
}