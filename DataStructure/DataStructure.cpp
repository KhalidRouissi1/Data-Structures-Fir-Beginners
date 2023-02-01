// DataStructure.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
using namespace std;
#include "Array.h"



int Notmain()
{
	int arrSize,key,indx, newSize;


	cout << "=====================================Array ADT demo=========================================\n";
	cout << "Enter the array size\n";
	cin >> arrSize;
	Array myArray(arrSize);
	myArray.Fill();
	//myArray.Append(200);
	// Search method 
	myArray.Dispaly();
	/*
	cout << "Give the key that you search for" << endl;
	cin >> key;

	cout << "The postion of your key @ " << myArray.Search(key) << endl;
	
	
	
	cout << "Enter new item to the array" << endl;
	int newItem;
	cin >> newItem;
	cout << "Give me its index";
	cin >> indx;
	myArray.Insert(indx,newItem);
	myArray.Dispaly();
	cout << "Give me what you need to delete";
	cin >> indx;
	myArray.Delete(indx);
	myArray.Dispaly();

	*/
	cout <<"Enter new size";
	cin >> newSize;
	myArray.Enlarge(newSize);
	cout << "The new size is " << myArray.getSize()<<endl;
	myArray.Dispaly();
	Array other(3);
	other.Fill(); 
	myArray.Merge(other);
	cout << "Array size is " << myArray.getSize()<<"Array length is "<<myArray.getlength() << endl;
	myArray.Dispaly();

	cout << "============================================================================================\n";
	return 0;
}