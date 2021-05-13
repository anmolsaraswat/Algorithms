#include<bits/stdc++.h>
using namespace std;

struct Node{
    int data;
    Node *left, *right;
    Node(int x)
    {
        this->data = x;
        left = right = NULL;
    }
};

int LISS(Node *root)
{
    if(root == NULL)
        return 0;
    int size_excl = LISS(root->left) + LISS(root->right);

    int size_incl = 1;
    if(root->left)
        size_incl += LISS(root->left->left) + LISS(root->left->right);
    if(root->right)
        size_incl += LISS(root->right->left) + LISS(root->right->right);

    return max(size_incl, size_excl);
}

int main()
{
    struct Node *root = new Node(20);
    root->left = new Node(8);
    root->left->left = new Node(4);
    root->left->right = new Node(12);
    root->left->right->left = new Node(10);
    root->left->right->right = new Node(14);
    root->right = new Node(22);
    root->right->right = new Node(25);

    cout << "Size of the Largest Independent Set : " << LISS(root);

    return 0;
}
