#pragma once
#include <iostream>
#include "Node.h"


class BinarySearchTree : Node
{
public: 
	BinarySearchTree();//constructor 
	Node *NewNode(int value);	//New Node Creation
	void Inorder(Node* root);	//Traverse InOrder
	Node *InsertNode(Node *node, int data);	//Insert a node
	Node *DeleteNode(Node *root, int data); //delete a node 
	Node* MinValueNode(Node* node);

	//Node CreateNewNode(int data);
	//Node InsertNode(Node *root, int data);//is used to add a new node to the current BST
	//Node Search(Node* root, int data); //is used to find a given key in the BST
private:
	Node *root;//begining


};


/*
  //TreeNode 
class BinarySearchTree
{
public:
	BinarySearchTree(int data)
	{
		this->data = data;
		this->L = nullptr;
		this->R = nullptr;
	}

	//Getter
	int Data()
	{
		return data;
	}
	void AddNode(BinarySearchTree* node)
	{
		//Insert left node 
		if (node->Data() < data)
		{
			//set left node, as we dont have one yet
			if (L == nullptr)
			{
				SetL(node);
			}
			else
			{
				// left tree to add this value itself
				L->AddNode(node);
			}
		}
		//insert Right node
		else if (node->Data() > data)//put it on right side
		{

			if (R == nullptr)
			{
				SetR(node);
			}
			//Right tree to add this value itself 
			else
			{
				R->AddNode(node);
			}

		}
	}
	void SetL(BinarySearchTree* L) { this->L = L; }
	void SetR(BinarySearchTree* R) { this->R = R; }
private:
	int data;
	BinarySearchTree* L;
	BinarySearchTree* R;

};
  */