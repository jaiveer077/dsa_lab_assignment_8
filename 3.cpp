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
Tree *insertBST(Tree *root, int v)
{
    if (root == nullptr)
        return new Tree(v);
    if (v < root->val)
        root->left = insertBST(root->left, v);
    else if (v > root->val)
        root->right = insertBST(root->right, v);
    else
        cout << "Duplicate not allowed: " << v << endl;
    return root;
}
Tree *findMin(Tree *root)
{
    while (root && root->left != nullptr)
        root = root->left;
    return root;
}
Tree *deleteBST(Tree *root, int key)
{
    if (root == nullptr)
        return root;
    if (key < root->val)
        root->left = deleteBST(root->left, key);
    else if (key > root->val)
        root->right = deleteBST(root->right, key);
    else
    {
        if (root->left == nullptr && root->right == nullptr)
        {
            delete root;
            return nullptr;
        }
        else if (root->left == nullptr)
        {
            Tree *temp = root->right;
            delete root;
            return temp;
        }
        else if (root->right == nullptr)
        {
            Tree *temp = root->left;
            delete root;
            return temp;
        }
        Tree *temp = findMin(root->right);
        root->val = temp->val;
        root->right = deleteBST(root->right, temp->val);
    }
    return root;
}
int maxDepth(Tree *root)
{
    if (root == nullptr)
        return 0;
    int leftDepth = maxDepth(root->left);
    int rightDepth = maxDepth(root->right);
    return max(leftDepth, rightDepth) + 1;
}
int minDepth(Tree *root)
{
    if (root == nullptr)
        return 0;
    if (root->left == nullptr && root->right == nullptr)
        return 1;
    if (root->left == nullptr)
        return minDepth(root->right) + 1;
    if (root->right == nullptr)
        return minDepth(root->left) + 1;
    return min(minDepth(root->left), minDepth(root->right)) + 1;
}
int main()
{
    Tree *root = nullptr;
    int elements[] = {50, 30, 20, 40, 70, 60, 80};
    for (int x : elements)
        root = insertBST(root, x);
    root = deleteBST(root, 20);
    root = deleteBST(root, 30);
    cout << "Maximum Depth of BST: " << maxDepth(root) << endl;
    cout << "Minimum Depth of BST: " << minDepth(root) << endl;
    return 0;
}