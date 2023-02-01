#pragma once
#include <iostream>
using namespace std;
class Node {
public:
	int data;
	Node* next ;
	Node() :data(0), next(NULL) {};
};

																							

class Stack
{
public :
	
	Stack():top(NULL)
	{}

		Node* top = new Node;
	bool isEmpty() {
		return (top == NULL);
	}



	void push(int ele) {

		Node* newNode=new Node;

		newNode->data = ele;
		if (isEmpty()) 
		{
			newNode->next = NULL;
			top = newNode;
		}
		else
		{
			newNode->next = top;
			top = newNode;
		}

	}
	int pop() {
		Node* delptr = top;
		int value = delptr->data;
		top = top->next;
		delete[]delptr;
		return value;
	}
	void display()
	{
		Node* temp = top;
		while (temp != NULL) {
			cout << temp->data <<"\t";
			temp = temp->next;
		 }
		cout << endl;
	}
	int count()
	{
		Node* temp = top;
		int counter=0;
		while (temp != NULL) {
			counter++;
			temp = temp->next;
		}
		return counter;
	}
	int peek() {
		return top->data;
	}
	bool isFound(int item) {
		Node* temp = top;
		while (temp != NULL) {
			if (temp->data == item) {
				return true;
			}
		}
		return false;
	}
	bool isFull()
	{
		Node* ptr = new Node();
		return (ptr == NULL);
	}
};




int Stackiiiiiiii() {
	Stack s;
	int item;

	for (int i = 0; i < 3; i++) {
		cout<< "Enter item to push"<<endl;
		cin >> item;
		s.push(item);
		s.display();
	
	}
	cout << endl <<"The item is " << s.isFound(3)<<endl;
	//cout << "The poped element is " <<s.pop() << endl;
	//cout << "The poped element is " << s.pop() << endl;
	s.display();
	return 0;
}																															