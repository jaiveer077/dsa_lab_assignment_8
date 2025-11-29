#include <iostream>
using namespace std;
struct Tree
{
    int data;
    Tree *left;
    Tree *right;
    Tree(int value)
    {
        data = value;
        left = right = nullptr;
    }
};
void preorder(Tree *root)
{
    if (root == nullptr)
        return;
    cout << root->data << " ";
    preorder(root->left);
    preorder(root->right);
}
void inorder(Tree *root)
{
    if (root == nullptr)
        return;
    inorder(root->left);
    cout << root->data << " ";
    inorder(root->right);
}
void postorder(Tree *root)
{
    if (root == nullptr)
        return;
    postorder(root->left);
    postorder(root->right);
    cout << root->data << " ";
}
int main()
{
    Tree *root = new Tree(1);
    root->left = new Tree(2);
    root->right = new Tree(3);
    root->left->left = new Tree(4);
    root->left->right = new Tree(5);
    cout << "Preorder: ";
    preorder(root);
    cout << "\nInorder: ";
    inorder(root);
    cout << "\nPostorder: ";
    postorder(root);
    cout << endl;
    return 0;
}