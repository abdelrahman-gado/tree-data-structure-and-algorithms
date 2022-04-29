#include <iostream>

// checking if the binary tree is a full binary tree

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

bool isFullBinaryTree(Node *root)
{
    if (root == nullptr)
        return true;
    
    if (root->left == nullptr && root->right == nullptr)
        return true;
    
    if (root->left != nullptr && root->right != nullptr)
        return (isFullBinaryTree(root->left) && isFullBinaryTree(root->right));
    
    return false;
}

int main() 
{
    
    Node *root = nullptr;
    root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->left->right = new Node(5);
    root->left->right->left = new Node(6);
    root->left->right->right = new Node(7);
    
    if (isFullBinaryTree(root))
        std::cout << "The tree is a full binary tree" << std::endl;
    else
        std::cout << "The tree is not a full binary tree" << std::endl;
    
    return 0;
}