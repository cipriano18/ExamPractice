#include "iostream"
#include "Employee.h"
#include "Numbers.h"
int main() {

    // employeeMenu;
     //employeeMenu.menu();
    Numbers* list1 = new Numbers(1);
    list1->insertNumbers(new Numbers(3));
    list1->insertNumbers(new Numbers(5));
    list1->insertNumbers(new Numbers(7));

    // Create and populate the second list
    Numbers* list2 = new Numbers(2);
    list2->insertNumbers(new Numbers(4));
    list2->insertNumbers(new Numbers(6));
    list2->insertNumbers(new Numbers(8));

    // Print the original lists
    std::cout << "Lista 1 original: " << std::endl;
    list1->printNumber();
    std::cout << "Lista 2 original: " << std::endl;
    list2->printNumber();

    // Create an instance to call the non-static method
    Numbers* head = new Numbers(1);

    // Intercalate the two lists and use the result directly
    head = head->intercalateLists(list1, list2);

    std::cout << "Lista intercalada: " << std::endl;
    head->printNumber();

    // Check if the intercalated list is ordered
    if (head->itIsOrdered(head)) {
        std::cout << "Lista ordenada" << std::endl;
    }
    else {
        std::cout << "Lista no ordenada" << std::endl;
    }
}