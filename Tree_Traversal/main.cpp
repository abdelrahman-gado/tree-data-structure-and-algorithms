#include <iostream>

struct Node
{
    int data;
    Node *left, *right;
    Node (int data)
    {
        this->data = data;
        left = right = nullptr;
    }
};

void preorderTraversal(Node *node)
{
    if (node == nullptr)
        return;
    
    std::cout << node->data << " -> ";
    preorderTraversal(node->left);
    preorderTraversal(node->right);
}

void postorderTraversal(Node *node)
{
    if (node == nullptr)
        return;
        
    postorderTraversal(node->left);
    postorderTraversal(node->right);
    std::cout << node->data << " -> ";
}

void inorderTraversal(Node *node)
{
    if (node == nullptr)
        return;
    
    inorderTraversal(node->left);
    std::cout << node->data << " -> ";
    inorderTraversal(node->right);
}

int main() 
{
    Node *root = new Node(1);
    root->left = new Node(12);
    root->right = new Node(9);
    root->left->left = new Node(5);
    root->left->right = new Node(6);
    
    std::cout << "Inorder Traversal : ";
    inorderTraversal(root);
    
    std::cout << "\nPreorder Traversal : ";
    preorderTraversal(root);
    
    std::cout << "\nPostorder Traversal : ";
    postorderTraversal(root);
    
    return 0;
}