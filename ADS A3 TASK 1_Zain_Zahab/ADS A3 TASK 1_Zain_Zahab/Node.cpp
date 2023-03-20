#include "Node.h"

Node::Node() {}

Node::Node(int data)
{
	this->data = data;
	this->left = nullptr;
	this->right = nullptr;
	this->root = root;
}
//getter
int Node::Data()
{
	return data;
}

//add node function covered in class 
void Node::AddNode(Node* node)
{
	//Insert left node 
	if (node->Data() < data)
	{
		//set left node, as we dont have one yet
		if ( left == nullptr)
		{
			SetL(node);
		}
		else
		{
			// left tree to add this value itself
			left->AddNode(node);
		}
	}
	//insert Right node
	else if (node->Data() > data)//put it on right side
	{

		if (right == nullptr)
		{
			SetR(node);
		}
		//Right tree to add this value itself 
		else
		{
			right->AddNode(node);
		}

	}
}

void Node::SetL(Node* L) { this->left = left;}
void Node::SetR(Node* R) { this->right = right;}


void Node::printTree(class Node* root, std::string indent, bool last) {
	if (root != nullptr) {
		std::cout << indent;
		if (last) {
			std::cout << "R----";
			indent += "   ";
		}
		else {
			std::cout << "L----";
			indent += "|  ";
		}
		std::cout << root->data << std::endl;
		printTree(root->left, indent, false);
		printTree(root->right, indent, true);
	}
}

int Node::count(Node* root) {
	if (root == NULL) {
		return 0;
	}
	else {
		return 1 + count(root->left) + count(root->right);
	}
}