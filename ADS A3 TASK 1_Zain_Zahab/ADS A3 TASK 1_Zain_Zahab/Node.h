#pragma once
#include <iostream>
class Node
{
public:
	Node();
	Node(int data);
	//stuff covered in class 
	int Data();
	void AddNode(Node* node);
	void SetL(Node* left);
	void SetR(Node* right);
	int count(Node* root);
	void printTree(class Node* root, std::string indent, bool last);

	int data;
    Node* left;
	Node* right;
	Node* root;
};