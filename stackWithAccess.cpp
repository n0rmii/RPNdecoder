#include <iostream>
#include <memory>
#include "stackWithAccess.hpp"

stack::stack () {
	top = nullptr;
	size = 0;
}

stack::~stack () {

}

void stack::push (int v) {
	if (size >= max_size) {
		std::cout<<"Stack full, cannot push\n";
		return;
	}
	std::unique_ptr<stackElem> temp (new stackElem);
	temp->ptr = std::move(top);
	temp->val = v;
	top = std::move(temp);
	size++;
}

int stack::pop () {
	if (size <= 0) {
		std::cout<<"Stack empty, cannot pop\n";
		return 0;
	}
	int temp = top->val;
	top = std::move(top->ptr); //I hope this deletes top
	size--;
	return temp;
}

const int& stack::operator[] (size_t index) const {
	if (index >= size) {
		std::cout<<"Tried to access nonexistent stack element\n";
		exit(2);
	}
	stackElem *temp = top.get();
	for (size_t i = 0; i < index; i++) {
		temp = temp->ptr.get();
	}
	return temp->val;
}

int& stack::operator[] (size_t index) {
	if (index >= size) {
		std::cout<<"Tried to access nonexistent stack element. The program will crash now\n";
		exit(1);
	}
	stackElem *temp = top.get();
	for (size_t i = 0; i < index; i++) {
		temp = temp->ptr.get();
	}
	return temp->val;
}

const size_t stack::getSize () const {
	return size;
}
