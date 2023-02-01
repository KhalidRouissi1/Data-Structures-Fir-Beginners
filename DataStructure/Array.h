#pragma once
#include <iostream>
using namespace std;
class Array
{
private:
	int size;
	int length;
	int* items;
public:
	Array(int arrSize) : size(arrSize), length(0)
	{

		items = new int[arrSize];
	}
	void Fill()
	{
		int itemsSize;
		cout << "How many items that you want to fill?" << endl;
		cin >> itemsSize;
		if (itemsSize > size) {
			cout << "You cannot exceed the array size" << endl;
			return;
		}
		else {
			for (int i = 0; i < itemsSize; i++) {
				cout << "Enter the item number " << i + 1 << endl;
				cin >> items[i];
				length++;
			}
		}
	}

	int getSize()
	{
		return size;

	}

	int getlength()
	{
		return length;
	}


	void Append(int newItem)
	{
		if (size <= length)
		{
			cout << "You can't make append because there is no space in the array" << endl;
		}
		else
		{
			items[length] = newItem;
			length++;
		}
	}
	void Insert(int indx, int newItem)
	{
		// Easy way 
		/*
		items[length] = items[indx];
		length++;
		items[indx] = newItem;
		*/

		// Shift way
		if (indx >= 0 && indx < size) {
			length++;
			for (int i = length; i > indx; i--) {
				items[i] = items[i - 1];
			}
			items[indx] = newItem;
		}
		else {
			cout << "Your index is wrong";
		}

	}

	int Search(int key)
	{
		int index = -1;
		for (int i = 0; i < length; i++) {
			if (items[i] == key)
			{
				index = i;
				break;
			}

		}
		return index;

	}

	void Delete(int index) {
		if (index >= 0 && index <= size) {
			for (int i = index; i < length - 1; i++) {
				items[i] = items[i + 1];
			}
			length--;
		}
		else
			cout << "Your index is wrong";

	}
	void Enlarge(int newSize) {
		if (newSize <= size) {
			cout << "Cannot be the new size same as the current size";
			return;
		}
		else {
			size = newSize;
			int* old = items;
			items = new int[size];
			for (int i = 0; i < length; i++)
			{
				items[i] = old[i];
			}
			delete[]old; // to delete pointers (Delete from heap)
		}
	}
	void Dispaly() {
		for (int i = 0; i < length; i++) {
			cout << items[i] << "\t";
		}
		cout << endl;
	}

	void Merge(Array other) {
		int newSize = size + other.getSize();
		size = newSize;
		int* old = items;
		items = new int[size];
		int i;
		for (i = 0; i < length; i++) {
			items[i] = old[i];
		}
		delete[]old;

		for (i = 0; i < other.getlength(); i++) {
			items[length] = other.items[i];
			length++;
		}
	}

};