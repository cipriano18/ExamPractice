#include "Numbers.h"


Numbers::Numbers(int number){
	this->number = number;
	this->next = nullptr;
}

void Numbers::setNumber(int number) {
	this->number = number;
}

int Numbers::getNumber()
{
	return this->number;
}

void Numbers::setNumberNext(Numbers* next)
{
	this->next = next;
}
Numbers* Numbers::getNext()
{
	return this->next;
}

void Numbers::insertNumbers(Numbers* newNumber) {
	Numbers* temp = this;
	if (this->next == nullptr) {
		this->next = newNumber;
	}
	else {
		while (temp->next != nullptr) {
			temp = temp->getNext();
		}
		temp->next = newNumber;
	}
}

void Numbers::printNumber(){
    Numbers* current = this;
	if (current == nullptr){
		cout << "NO hay numeros en la lista" << endl;
	}
	else{
		while (current != nullptr) {
            cout << current->getNumber() << "->";
			current = current->getNext();
		}
	}
}

void Numbers::removeDuplicates(){
   Numbers* current = this;
    while (current != nullptr && current->getNext() != nullptr) {
        Numbers* runner = current;

        while (runner->getNext() != nullptr) {
            if (runner->getNext()->getNumber() == current->getNumber()) {
                Numbers* duplicate = runner->getNext();
                runner->setNumberNext(duplicate->getNext());
                delete duplicate; 
            }
            else {
                runner = runner->getNext();
            }
        }
        current = current->getNext(); 
    }
}
void Numbers::insertAtPosition(Numbers*& head, int value, int position) {
    Numbers* newNode = new Numbers(value);
    if (position == 1) {
        newNode->setNumberNext(head);
        head = newNode;
        return;
    }

    Numbers* temp = head;
    int currentPosition = 1;
    while (temp != nullptr && currentPosition < position - 1) {
        temp = temp->getNext();
        currentPosition++;
    }

    if (temp == nullptr) {
        std::cout << "Error: La posicion " << position << " es mayor que el size de la lista." << std::endl;
        delete newNode; 
        return;
    }
    newNode->setNumberNext(temp->getNext());
    temp->setNumberNext(newNode);
}


int Numbers::totalNodes(){
	Numbers* current = this;
	int amount = 0;
		while (current->getNext() != nullptr){
			current = current->getNext();
			amount++;
		}
	return amount;
}

bool Numbers::itIsOrdered(Numbers* head){
    if (head == nullptr || head->getNext() == nullptr) {
        return true;
    }
    else{
        while (head->getNext() != nullptr) {
            if (head->getNumber() > head->getNext()->getNumber()){
                return false;
            }
            head = head->getNext();
        }
    }

    return true;
}

void Numbers::removeMin(Numbers*& head){
    if (head == nullptr) {
        return; 
    }
    Numbers* actual = head;
    Numbers* minimo = head;
    Numbers* anteriorMinimo = nullptr;
    Numbers* anterior = nullptr;

    while (actual != nullptr) {
        if (actual->getNumber() < minimo->getNumber()) {
            minimo = actual;
            anteriorMinimo = anterior;
        }
        anterior = actual;
        actual = actual->getNext();
    }
    if (minimo == head) {
        head = head->getNext();
    }
    else {
        anteriorMinimo->setNumberNext(minimo->getNext());
    }
    delete minimo;
}

Numbers* Numbers::intercalateLists(Numbers* list1, Numbers* list2){
    if (list1 == nullptr) return list2;
    if (list2 == nullptr) return list1;

    Numbers* head = nullptr;
    Numbers* tail = nullptr;

    while (list1 != nullptr && list2 != nullptr) {
        if (head == nullptr) {
            head = list1;
            tail = head;
            list1 = list1->getNext();
        }
        else {
            tail->setNumberNext(list1);
            tail = tail->getNext();
            list1 = list1->getNext();
        }

        tail->setNumberNext(list2);
        tail = tail->getNext();
        list2 = list2->getNext();
    }

    if (list1 != nullptr) {
        tail->setNumberNext(list1);
    }

    if (list2 != nullptr) {
        tail->setNumberNext(list2);
    }
    return head;
}
