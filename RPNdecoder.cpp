#include <iostream>
#include "stackWithAccess.hpp"

int main(int argc, char *argv[]){
	stack instructionStack;
	instructionStack.push(7);
	std::cout<<instructionStack.pop();
	return 0;
}
