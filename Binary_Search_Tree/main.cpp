#include <iostream>

struct Node
{
    int key;
    Node *left, *right;
    Node (int d)
        : key {d}, left {nullptr}, right {nullptr}
    {
    }
};

void inorder(Node *root)
{
    if (root != nullptr)
    {
        inorder(root->left);
        std::cout << root->key << " -> ";
        inorder(root->right);
    }
}

Node *insert(Node *node, int key)
{
    if (node == nullptr) return new Node(key);
    
    if (key < node->key)
        node->left = insert(node->left, key);
    else
        node->right = insert(node->right, key);
        
    return node;
}

Node *minValueNode (Node *node)
{
    Node *current = node;
    while (current && current->left != nullptr)
    {
        current = current->left;
    }
    return current;
}

Node *deleteNode(Node *root, int key)
{
    if (root == nullptr) return root;
    
    if (key < root->key)
        root->left = deleteNode(root->left, key);
    else if (key > root->key)
        root->right = deleteNode(root->right, key);
    else
    {
        if (root->left == nullptr)
        {
            Node *temp = root->right;
            delete root;
            return temp;
        }
        else if (root->right == nullptr)
        {
            Node *temp = root->left;
            delete root;
            return temp;
        }
        
        Node *temp = minValueNode(root->right);
        root->key = temp->key;
        root->right = deleteNode(root->right, temp->key);
    }
    
    return root;
}







int main() 
{
    Node *root = nullptr;
    root = insert(root, 8);
    root = insert(root, 3);
    root = insert(root, 1);
    root = insert(root, 6);
    root = insert(root, 7);
    root = insert(root, 10);
    root = insert(root, 14);
    root = insert(root, 4);

    std::cout << "Inorder traversal: ";
    inorder(root);

    std::cout << "\nAfter deleting 10\n";
    root = deleteNode(root, 10);
    std::cout << "Inorder traversal: ";
    inorder(root);
    return 0;
}