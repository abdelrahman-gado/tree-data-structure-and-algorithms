#include <iostream>

struct Node
{
    int key;
    Node *left, *right;
    Node (int k)
    {
        key = k;
        left = right = nullptr;
    }
};

int countNumNodes(Node *root)
{
    if (root == nullptr)
        return 0;
    return (1 + countNumNodes(root->left) + countNumNodes(root->right));
}

bool checkComplete(Node *root, int index, int numberofNodes)
{
    if (root == nullptr)
        return true;
        
    if (index >= numberofNodes)
        return false;
    
    return (checkComplete(root->left, 2*index+1, numberofNodes) && checkComplete(root->right, 2*index+2, numberofNodes));
}




int main() 
{
    struct Node *root = NULL;
    root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->left->right = new Node(5);
    root->right->left = new Node(6);
    
    int node_count = countNumNodes(root);
    int index = 0;

    if (checkComplete(root, index, node_count))
        std::cout << "The tree is a complete binary tree\n";
    else
        std::cout << "The tree is not a complete binary tree\n";

    
    return 0;
}