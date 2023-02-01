#pragma once
#include <iostream>
using namespace std;
class Node {
public  : 
	int data;
	Node* next;
	Node():data(0),next(NULL)
	{}
};



class Queue
{
public:
	Node* front = new Node;
	Node* rear = new Node;
	Queue():front(NULL),rear(NULL)
	{}

	void enqueue(int item)
	{
		Node* newNode = new Node;
		newNode->data = item;
		if (isEmpty()) 
			front=rear = newNode;
		else {
			rear->next = newNode;
			rear = newNode;
		}
	}

	void dequeue()
	{
		int delValue;
		if (isEmpty()) {
			cout << "There is no items in the queue";
		}
		else if (front == rear) {
			delValue = front->data;
			delete front;
			front = rear = NULL;
			cout << "The item was delete it is " << delValue << endl;
		}
		else {
			Node* delptr = front;
			front = front->next;
			delValue = delptr->data;
			delete delptr;
			cout << "The item was delete it is " << delValue << endl;
		}
	}
	int getFront()
	{
		return front->data;
	}
	int getRear()
	{
		return rear->data;
	}
	bool isEmpty() 
	{
		return(front == NULL);//&& rear == NULL);
	}
	bool isFound(int item)
	{
		Node* temp = front;
		bool find = false;
		while (temp != NULL)
		{
			if (item == temp->data)
				find = true;
			temp = temp->next;
		}
		return find;

	}
	void display() {

		if (isEmpty()) 
		{
			cout << "Queue is empty";
		}
		else
		{
			Node* temp = front;
			while (temp != NULL)
			{
				cout << temp->data << "\t";
				temp = temp->next;
			}
			cout << endl;
		}
	}
	int count()
	{
		Node* temp = front;
		int counter=0;
		while (temp != NULL)
		{
			counter++;
			temp = temp->next;
		}
		return 0;
	}
	bool isFull()
	{
		// it works for the arrays to check if there is a place in size to add an item
	}
	void Clear()
	{
		while (!isEmpty()) {
			dequeue();
		}
	}


};

int mainOfQueue() {
	Queue q; 
	int item;
	for (int i = 0; i < 3; i++) {
		cout << "Give me your item to put it in the queue" << endl;
		cin >> item;
		q.enqueue(item);
	}
	/*q.dequeue();
	q.display();

	q.dequeue();
	q.display();


	q.dequeue();
	q.display();
	q.dequeue();*/


	q.Clear();
	q.display();



	return 0;
}