#include <iostream>
#include <string>
#include <cmath>
#include "stackWithAccess.hpp"

int main(int argc, char *argv[]){
	stackf dataStack;
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
				case '^':
					tmpVal = dataStack.pop();
					dataStack.push(std::pow(dataStack.pop(), tmpVal));
				case ' ':
					if (valHolder != "") {
						dataStack.push(std::stof(valHolder));
						valHolder = "";
					}
					break;
				default:
					if(s >= '.' && s <= '9'){
						valHolder += s;
					}
					else{
						std::cout<<"\nIncorrect input detected: "<<s<<'\n';
					}
					break;
			}
		}
		if(dataStack.getSize() > 0){
			std::cout<<"Output: "<<dataStack.pop()<<std::endl;
		}
		else{
			std::cout<<"Program exit or error";
		}
	}
	return 0;
}
