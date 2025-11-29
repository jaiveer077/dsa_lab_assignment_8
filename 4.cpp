#include <bits/stdc++.h>
using namespace std;
struct Tree
{
    int val;
    Tree *left;
    Tree *right;
    Tree(int v)
    {
        val = v;
        left = right = nullptr;
    }
};
bool isBSTUtil(Tree *root, long long minVal, long long maxVal)
{
    if (root == nullptr)
        return true;
    if (root->val <= minVal || root->val >= maxVal)
        return false;
    return isBSTUtil(root->left, minVal, root->val) &&
           isBSTUtil(root->right, root->val, maxVal);
}
bool isBST(Tree *root)
{
    return isBSTUtil(root, LLONG_MIN, LLONG_MAX);
}
int main()
{
    Tree *root = new Tree(50);
    root->left = new Tree(30);
    root->right = new Tree(70);
    root->left->left = new Tree(20);
    root->left->right = new Tree(40);
    root->right->left = new Tree(60);
    root->right->right = new Tree(80);
    if (isBST(root))
        cout << "This tree IS a BST" << endl;
    else
        cout << "This tree is NOT a BST" << endl;
    return 0;
}