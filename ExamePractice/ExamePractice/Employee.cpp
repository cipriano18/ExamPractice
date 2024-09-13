#include "Employee.h"

Employee::Employee()
{
}
Employee::Employee(int id, int hoursWorked){
	this->id = id;
	this->hoursWorked = hoursWorked;
	this->next = nullptr;
}

void Employee::setId(int id){
	this->id = id;
}
void Employee::setHoursWorked(int hoursWorked){
	this->hoursWorked = hoursWorked;
}
void Employee::setNext(Employee* next) {
    this->next = next;
}
int Employee::getId()
{
	return this->id;
}

int Employee::getHoursWorked()
{
	return this->hoursWorked;
}

Employee* Employee::getNext(){
	return this->next;
}

void Employee::insertEmployee(Employee* newEmployee) {
    Employee* temp = this;
    if (this->next == nullptr) {
        this->next = newEmployee;
    }
    else {
        while (temp->next != nullptr) {
            temp = temp->getNext();
        }
        temp->next = newEmployee;
    }
}

void Employee::printEmployee(){
    Employee * current = this;
    if (current == nullptr){
        cout << "No hay empleados ingresados" << endl;
    }
    else{
        while (current != nullptr) {
            cout << " ID " << current->getId() << " Horas trabajadas " << current->getHoursWorked() << endl;
            current = current->getNext();
        }
    }
}
Employee* Employee::addEmployee(Employee* head) {
    Employee* consolidatedHead = nullptr;
    Employee* consolidatedTail = nullptr;
    Employee* current = head;

    while (current != nullptr) {
        Employee* search = consolidatedHead;
        bool found = false;
        while (search != nullptr) {
            if (search->getId() == current->getId()) {
                search->setHoursWorked(search->getHoursWorked() + current->getHoursWorked());
                found = true;
                break;
            }
            search = search->getNext();
        }
        if (!found) {
            Employee* newEmployee = new Employee(current->getId(), current->getHoursWorked());
            if (consolidatedHead == nullptr) {
                consolidatedHead = newEmployee;
                consolidatedTail = newEmployee;
            }
            else {
                consolidatedTail->setNext(newEmployee);
                consolidatedTail = newEmployee;
            }
        }
        current = current->getNext();
    }
    return consolidatedHead; 
}


void Employee::menu() {
    Employee* head = nullptr;
    Employee* consolidatedList = nullptr;
    int option ;

    do {
        cout << "Menu:" << endl;
        cout << "1. Ingresar nuevo empleado" << endl;
        cout << "2. Consolidar empleados" << endl;
        cout << "3. Imprimir lista de empleados" << endl;
        cout << "4. Salir" << endl;
        cout << "Ingrese su opcion: ";
        cin >> option;

        switch (option){
        case 1: {
            int id, hoursWorked;
            cout << "Ingrese ID del empleado: ";
            cin >> id;
            cout << "Ingrese horas trabajadas: ";
            cin >> hoursWorked;

            Employee* newEmployee = new Employee(id, hoursWorked);

            if (head == nullptr) {
                head = newEmployee;
            }
            else {
                head->insertEmployee(newEmployee);
            }
            break;
        }
        case 2: {
            consolidatedList = addEmployee(head);
            break;
        }
        case 3: {
            cout << "LISTA CON TODOS LOS EMPLEADOS " << endl;
            head->printEmployee();
            cout << "LISTA CON LA SUMA DE EMPLEADOS"<<endl;
            consolidatedList->printEmployee();
            break;
        }
        default: {
            cout << "Opcion invalida. Intente nuevamente." << endl;
            break;
        }
        }
        } while (option != 4);
}