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

int depth(Node *node)
{
    int d = 0;
    while (node != nullptr)
    {
        d++;
        node = node->left;
    }
    return d;
}

bool isPrefectR(Node *root, int d, int level=0)
{
    if (root == nullptr)
        return true;
    
    if (root->left == nullptr && root->right == nullptr)
        return (d == level+1);
    
    if (root->left == nullptr || root->right == nullptr)
        return false;
        
    return isPrefectR(root->left, d, level+1) && isPrefectR(root->right, d, level+1);
}

bool isPerfect(Node *root)
{
    int d = depth(root);
    return isPrefectR(root, d);
}


int main() 
{
    Node *root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->left->right = new Node(5);
    root->right->left = new Node(6);
    
    if (isPerfect(root))
        std::cout << "The tree is a perfect binary tree\n";
    else
        std::cout << "The tree is not a perfect binary tree\n";
    
    return 0;
}