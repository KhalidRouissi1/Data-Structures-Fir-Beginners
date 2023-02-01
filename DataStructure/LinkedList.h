#pragma once
#include <iostream>
#include <iostream>
using namespace std;
class Node {
public:
	int Data;
	Node* Next; 
};

class LinkedList
{
public:
	Node* head;

	LinkedList() {
		head =NULL;
	}
	bool isEmpty() 
	{
		return (head == NULL);
	}  
	void inesrtFirst(int newValue)
	{
		Node* newNode = new Node;
		newNode->Data = newValue;
		
		if (isEmpty()) 
		{
			newNode->Next = NULL;
			head = newNode;
		}


		else
		{
			newNode->Next = head;
			head = newNode;
		}


	}


	void display() {
		Node* temp = head;

		while (temp != NULL) {
			cout << temp->Data << "\t";;
			temp = temp->Next;	
		}
		cout << "\n";

	}
	int counter() {
		int counter=0;
		Node* temp = head;

		while (temp != NULL) {
			counter++;
			temp = temp->Next;
		}
		return counter;
	}
	bool isFound(int item) {
		
		Node* temp = head;
		while (temp != NULL) {
			
			if (temp->Data == item) {
				return true;
			}
			temp = temp->Next;
		}
		return false;
	}

	void  insertBefore(int afterItem,int item) {
		if (isEmpty()) {
			inesrtFirst(item);
		}
		if(isFound(afterItem)){
		Node* temp = head;
		Node* newNode= new Node;

		while (temp->Data != afterItem && temp != NULL)
		{
			temp = temp->Next;
		}
		newNode->Data= item;
		newNode->Next = temp->Next;
		temp->Next = newNode;
		}
		else {
			cout << "Item not founds !!!!!!!"<<endl;
		}
	}
	void appedn(int newItem) {
		if (isEmpty()) {
			inesrtFirst(newItem);
		}
		else {
			Node* newNode = new Node;
			Node* temp = head;
			// we have test here with temp->Next != NULL to stop in the last element in the LinkedList 
			while (temp->Next != NULL) {
				temp = temp->Next;
			}
			newNode->Data = newItem;
			newNode->Next = temp->Next;
			temp->Next = newNode;

			}
		}

	void Delete(int item) {

		Node* delPtr = head;
		if (head->Data == item) {
			head = head->Next;
			delete[]delPtr;

		}
		else {
			Node* prvPtr = head;
			while (delPtr->Data != item) {
					prvPtr = delPtr;
					delPtr = delPtr->Next;
			}
		
			prvPtr->Next = delPtr->Next;

			delete[]delPtr;
		}

	
		
	}
									   
};
/*
int main() {

	LinkedList lst;



	if (lst.isEmpty()) {
		cout << "List is empty"<<endl;
	}
	else
		cout << "List contains " << lst.counter()<<endl; 


	lst.inesrtFirst(55);
	lst.display();
	lst.inesrtFirst(100);
	lst.display();
	lst.inesrtFirst(200);
	lst.display();
	cout << "The list containes " << lst.counter() << " items" << endl;
	if (lst.isFound(200)) {
		cout << "Is Founded"<<endl;
	}
	else {
		cout << "Not founded"<<endl;
	}

	//lst.insertBefore(100, 7000);
	cout << "After Append" << endl;
	lst.appedn(500);
	lst.display();

	cout << "After Delete " << endl;
	lst.Delete(100);
	lst.display();
}
*/