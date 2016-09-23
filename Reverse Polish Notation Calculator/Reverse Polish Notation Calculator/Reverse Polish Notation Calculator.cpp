// Reverse Polish Notation Calculator.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <string>

using namespace std;

struct node {
	int data;
	node *next;
};

class Stack {
	node *top;
public:
	Stack() { top = NULL; };
	~Stack();
	void push(int data);
	int pop();
	void display();
};

// Push an integer onto the stack.
void Stack::push(int data) {
	node *temp;
	temp = new node;
	//cout << "Enter data: " << endl;
	temp->data = data;
	temp->next = top;
	top = temp;
}

// Pull an integer from the stack.
int Stack::pop() {
	if (top != NULL) {
		int stuff;
		node *temp = top;
		stuff = temp->data;
		top = top->next;
		//cout << temp->data << "deleted" << endl;
		delete temp;
		return stuff;
	}
	else {
		//cout << "Stack empty." << endl;
		return 0;
	}
}

void Stack::display() {
	node *temp = top;
	while (temp != NULL) {
		cout << temp->data << " ";
		temp = temp->next;
	}
	cout << endl;
}

Stack::~Stack() {
	node *temp = top;
	top = top->next;
	delete temp;
}


class Calculator {
public:
	Stack stack;
	string receiveInput();
	// calculate (parameters?)
	void CalculatorAPI();
	void pushInput(string s);
	bool Calculate();
};

string Calculator::receiveInput() {
	string input;
	cout << "Enter an operation: ";
	cin >> input;
	return input;
}

void Calculator::CalculatorAPI() {
	cout << "This is a Reverse Polish Notation Calculator." << endl;
	bool exit = false;
	while (!exit) {
		exit = Calculate();
	}
	cout << "Exiting.\nThank you for calculating things!" << endl;
}

void Calculator::pushInput(string s) {

}

bool Calculator::Calculate()
{
	cout << "Enter an operation or q to quit." << endl;
	pushInput(receiveInput()); // Receive string from user, then push to stack.

}

int main()
{
	Calculator calc;
	calc.CalculatorAPI();
    return 0;
}

