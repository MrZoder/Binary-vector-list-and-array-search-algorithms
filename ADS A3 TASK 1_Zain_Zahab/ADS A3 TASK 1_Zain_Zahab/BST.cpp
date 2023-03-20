#include "BST.h"
#include <iostream>


BinarySearchTree::BinarySearchTree() : Node(data) {}

Node *BinarySearchTree::NewNode(int value) //creating node
{
    Node* temp = (class Node*)malloc(sizeof(class Node));
    temp->Node::data = value;
    temp->Node::left = NULL;
    temp->Node::right = NULL;
    return temp;
    
}
//InOrder Traversal 
void BinarySearchTree::Inorder(Node *root)
{
    if(root != NULL)
    {
        //Move left 
        Inorder(root->left);

        //Move root
        std::cout << root->data << " -->";

        //Move right 
        Inorder(root->right);
    }
    
}
//insert a node 
Node *BinarySearchTree::InsertNode(Node *node, int data)
{   //return a new node if / when tree is empty 
    if (node == NULL) return NewNode(data);

    if (data < node->data) {
        node->left = InsertNode(node->left, data);
    }
    else {
        node->right = InsertNode(node->right, data);
    }

    return node;
       
    
}
//Find Inorder successor
Node * BinarySearchTree::MinValueNode(Node* node)
{
    Node* current = node;

    //find furthest left leaf
    while (current && current->left != NULL)
        current = current->left;

    return current;
}
//deleting node 
Node* BinarySearchTree::DeleteNode(Node* root, int data)
{
    //return if tree is NULL
    if (root == NULL)return root;

    //find node we want to delete 
    if(data < root->data)
       root->left = DeleteNode(root->left, data);
    else if (data > root->data)
        root->right = DeleteNode(root->right, data);
    else {
        // If the node is with only one child or no child
        if (root->left == NULL) {
            Node* temp = root->right;
            free(root);
            return temp;
        }
        else if (root->right == NULL) {
            Node* temp = root->left;
            free(root);
            return temp;
        }

        // If the node has two children
         Node* temp = MinValueNode(root->right);

        // Place the inorder successor in position of the node to be deleted
        root->data = temp->data;

        // Delete the inorder successor
        root->right = DeleteNode(root->right, temp->data);
    }
    return root;
}



/*BinarySearchTree::BinarySearchTree() : Node(data){}

Node *CreateNewNode(int data)
{
	Node* newnode = (class Node*)malloc(sizeof(class Node));
	newnode->data = data;
	newnode->left = NULL;
	newnode->right = NULL;
	return newnode;
}
Node *InsertNode(Node* root, int data)
{
    Node *temp = CreateNewNode(data);
    // If BST doesn't exist
    // create a new node as root
    // or it's reached when
    // there's no any child node
    // so we can insert a new node here
    if ( root == NULL)
    {
        
      
    }
    return 0;
}
Node *Search(Node* root, int data)
{
    return 0;
}*/