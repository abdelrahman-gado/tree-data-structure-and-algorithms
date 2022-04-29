#include <iostream>

// checking if a binary tree is height balanced

class node
{
public:
    int item;
    node *left;
    node *right;
    node (int data)
        : item {data}, left {nullptr}, right {nullptr}
    {
    }
};

bool checkHeightBalance(node *root, int *height)
{
    int leftHeight = 0;
    int rightHeight = 0;
    int l = 0;
    int r = 0;
    
    if (root == nullptr)
    {
        *height = 0;
        return true;
    }
    
    l = checkHeightBalance(root->left, &leftHeight);
    r = checkHeightBalance(root->right, &rightHeight);
    
    *height = (leftHeight > rightHeight ? leftHeight : rightHeight) + 1;
    if ((leftHeight - rightHeight >= 2) || (rightHeight - leftHeight >= 2))
        return false;
    else
        return l && r;
}



int main() 
{
    int height = 0;

    node *root = new node(1);
    root->left = new node(2);
    root->right = new node(3);
    root->left->left = new node(4);
    root->left->right = new node(5);

    if (checkHeightBalance(root, &height))
        std::cout << "The tree is balanced";
    else
        std::cout << "The tree is not balanced";
    
    return 0;
}