#include <iostream>

struct node
{
    int data;
    node *left;
    node *right;
    node(int d)
    {
        data = d;
        left = right = nullptr;
    }
};

void traversePreOrder(node *temp)
{
    if (temp != nullptr)
    {
        std::cout << temp->data << " -> ";
        traversePreOrder(temp->left);
        traversePreOrder(temp->right);
    }
}

void traversePostOrder(node *temp)
{
    if (temp != nullptr)
    {
        traversePostOrder(temp->left);
        traversePostOrder(temp->right);
        std::cout << temp->data << " -> ";
    }
}

void traverseInOrder(node *temp)
{
    if (temp != nullptr)
    {
        traverseInOrder(temp->left);
        std::cout << temp->data << " -> ";
        traverseInOrder(temp->right);
    }
}


int main() 
{
    node *root = new node(1);
    root->left = new node(2);
    root->right = new node(3);
    root->left->left = new node(4);
    
    std::cout << "preorder traversal: ";
    traversePreOrder(root);
    
    std::cout << "\nInorder traversal: ";
    traverseInOrder(root);
    
    std::cout << "\nPostorder traversal: ";
    traversePostOrder(root);
    
    return 0;
}