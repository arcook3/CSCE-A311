#pragma once

#ifndef myStack
#define myStack

#include <iostream>
#include <conio.h>

using namespace std;

struct node {
	int data;
	node *next;
};

class Stack {
	node *top;
public:
	Stack() { top = NULL };
	~Stack();
	void push();
	void pop();
	void display();
};

void Stack::push() {
	node *temp;
	temp = new node;
	cout << "Enter data: " << endl;
	cin >> temp->data;
	temp->next = top;
	top = temp;
}

void Stack::pop() {
	if (top != NULL) {
		node *temp = top;
		top = top->next;
		cout << temp->data << "deleted" << endl;
		delete temp;
	}
	else {
		cout << "Stack empty.") << endl;
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

#endif