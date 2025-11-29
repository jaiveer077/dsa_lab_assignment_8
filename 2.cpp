#include <iostream>
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
    return root;
}
Tree *searchRecursive(Tree *root, int key)
{
    if (root == nullptr || root->val == key)
        return root;

    if (key < root->val)
        return searchRecursive(root->left, key);
    else
        return searchRecursive(root->right, key);
}
Tree *searchNonRecursive(Tree *root, int key)
{
    while (root != nullptr)
    {
        if (key == root->val)
            return root;
        else if (key < root->val)
            root = root->left;
        else
            root = root->right;
    }
    return nullptr;
}
Tree *findMaximum(Tree *root)
{
    if (root == nullptr)
        return nullptr;
    while (root->right != nullptr)
        root = root->right;
    return root;
}
Tree *findMinimum(Tree *root)
{
    if (root == nullptr)
        return nullptr;
    while (root->left != nullptr)
        root = root->left;
    return root;
}
Tree *inorderSuccessor(Tree *root, Tree *target)
{
    if (target == nullptr)
        return nullptr;
    if (target->right != nullptr)
        return findMinimum(target->right);
    Tree *successor = nullptr;
    while (root != nullptr)
    {
        if (target->val < root->val)
        {
            successor = root;
            root = root->left;
        }
        else if (target->val > root->val)
        {
            root = root->right;
        }
        else
            break;
    }
    return successor;
}
Tree *inorderPredecessor(Tree *root, Tree *target)
{
    if (target == nullptr)
        return nullptr;
    if (target->left != nullptr)
        return findMaximum(target->left);
    Tree *predecessor = nullptr;
    while (root != nullptr)
    {
        if (target->val > root->val)
        {
            predecessor = root;
            root = root->right;
        }
        else if (target->val < root->val)
        {
            root = root->left;
        }
        else
            break;
    }
    return predecessor;
}
int main()
{
    Tree *root = nullptr;
    int arr[] = {50, 30, 70, 20, 40, 60, 80};
    for (int x : arr)
        root = insertBST(root, x);
    int key = 40;
    Tree *r = searchRecursive(root, key);
    cout << "Recursive Search: " << (r ? "Found" : "Not Found") << endl;
    Tree *nr = searchNonRecursive(root, key);
    cout << "Non-Recursive Search: " << (nr ? "Found" : "Not Found") << endl;
    Tree *minNode = findMinimum(root);
    cout << "Minimum element: " << minNode->val << endl;
    Tree *maxNode = findMaximum(root);
    cout << "Maximum element: " << maxNode->val << endl;
    Tree *succ = inorderSuccessor(root, r);
    if (succ)
        cout << "In-order Successor of " << key << " is " << succ->val << endl;
    else
        cout << "No In-order Successor exists\n";
    Tree *pred = inorderPredecessor(root, r);
    if (pred)
        cout << "In-order Predecessor of " << key << " is " << pred->val << endl;
    else
        cout << "No In-order Predecessor exists\n";
    return 0;
}