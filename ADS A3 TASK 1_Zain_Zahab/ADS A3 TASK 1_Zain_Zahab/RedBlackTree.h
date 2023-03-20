#pragma once
#include "BST.h"
//This Doesn't matter Anymore. 
typedef Node* NodePtr;

class RedTree : public BinarySearchTree
{
private:

	NodePtr root;
	NodePtr TNULL;

	void initializeNULLNode(NodePtr node, NodePtr parent) {
		node->data = 0;
		node->parent = parent;
		node->left = nullptr;
		node->right = nullptr;
		node->color = 0;
	}
	
	
};