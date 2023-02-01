#pragma once
#include <iostream>
using namespace std;



class Node 
{
public : 
	int data;
	Node* left;
	Node* right;
	Node(int value)
	{
		data = value;
		right = left = NULL;
	}

};


class BST 
{
public:
	Node* root;
	BST() {
		root = NULL;
	}
	//pnode is root 
	Node * Insert(Node* pnode , int item)
	{


		if (pnode == NULL) {
			Node* newNode = new Node(item);
			pnode = newNode;
		}



		else if (pnode->data > item) {
			pnode->left =  Insert(pnode->left, item);
		}


		else
		{
			pnode->right = Insert(pnode->right, item);
		}
		return pnode;
	}



	void insert(int item)
	{
		root = Insert(root, item);
	}

	void preOrder(Node* r)
	{
		if(r  == NULL)
			return;
		cout << r->data << "\t";
		preOrder(r->left);
		preOrder(r->right);
	}
	void InOrder(Node* r)
	{
		if (r == NULL)
			return;
		InOrder(r->left);
		cout << r->data << "\t";
		InOrder(r->right);
	}

	void postOrder(Node* r)
	{
		if (r == NULL)
			return;
		postOrder(r->left);
		postOrder(r->right);
		cout << r->data << "\t";
	}

	bool search(int item , Node* r)
	{

		if ( r == NULL)
		{
			return false;
		} 
		else
		{

			if (item == r->data)
			{
				return true;
			}
			else if (item > r->data)
			{
				search(item, r->right);
			}
			else
			{
				search(item, r->left);
			}
		}


	
	}
	int min(Node*r)
	{

		// witohut Recursion way 
		if (r == NULL)
			return NULL;
		else
		{
			while (r->left != NULL)
			{
				r = r->left;
			}
			return r->data;
		}
	

	}
	Node* max(Node* r)
	{
		if (r == NULL)
			return NULL;
		else if (r->right == NULL)
		{
			return r;
		}
		else
		{
			return max(r->right);
		}
	
	}

	Node* Delete(Node* r,int item)
	{
		if (r == NULL)
			return NULL;
		if (item < r->data)
			r->left =  Delete(r->left, item);
		else if(item > r->data)
			r->right = Delete(r->right, item);
		else
		{
			if (r->left == NULL && r->right == NULL)
				r = NULL;
			else if (r->left !=NULL && r->right == NULL)//one child on the left
			{ 
				r->data = r->left->data;
				delete[]r->left;
				r->left = NULL;
			}
			else if (r->left == NULL && r->right != NULL)//one child on the right
			{
				r->data = r->right->data;
				delete[]r->right;
				r->right = NULL;
			}
			else
			{
				Node* pre = max(r->left);
				r->data = pre->data;
				Delete(r->left, pre->data);
			}


		}
		return r;
		

	}


};



int main()
{
	BST btree;
	// 45 15 79 90 10 55 12 20 50
	btree.insert(45);
	btree.insert(15);
	btree.insert(79);
	btree.insert(910);
	btree.insert(10);
	btree.insert(55);
	btree.insert(12);
	btree.insert(20);
	btree.insert(50);
	btree.InOrder(btree.root);
	cout << endl;
	
	//cout << endl << btree.search(20, btree.root) << endl;
	//cout << "-------------------------------- - " << endl;
	//cout << btree.max(btree.root);

	btree.Delete(btree.root , 55);
	btree.InOrder(btree.root);
	cout << endl;
	
	return 0;
	
}