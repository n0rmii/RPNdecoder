#include <iostream>
#include <string>
#include "stackWithAccess.hpp"

int main(int argc, char *argv[]){
	stack dataStack;
	bool running = true;
	std::string input;
	std::string valHolder = "";
	int tmpVal;
	while(running){
		std::cout<<"Input: ";
		std::getline(std::cin, input);
		for (char s : input) {
			switch (s) {
				case 'e':
					running = false;
					break;
				case '+':
					dataStack.push(dataStack.pop() + dataStack.pop());
					break;
				case '-':
					tmpVal = dataStack.pop(); // I need to switch the positions of pops
					dataStack.push(dataStack.pop() - tmpVal);
					break;
				case '*':
					dataStack.push(dataStack.pop() * dataStack.pop());
					break;
				case '/':
					tmpVal = dataStack.pop(); // I need to switch the positions of pops
					dataStack.push(dataStack.pop() / tmpVal);
					break;
				case ' ':
					if (valHolder != "") {
						dataStack.push(std::stoi(valHolder));
						valHolder = "";
					}
					break;
				default:
					valHolder += s;
					// dataStack.push(s - '0');
			}
		}
		std::cout<<"Output: "<<dataStack.pop()<<std::endl;
	}
	return 0;
}
