#pragma once
#include <iostream>
#include "Node.h"
bool NodeExists(Node* Node, int key)//does the node exist ? 
{
    if (Node == NULL)
        return false;

    if (Node->data == key)
        return true;

    bool result1 = NodeExists(Node->left, key);
        if (result1) return true;

    bool result2 = NodeExists(Node->right, key);
        return result2;

}
