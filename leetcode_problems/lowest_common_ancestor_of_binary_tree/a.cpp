#include <bits/stdc++.h>
typedef double _d;
using namespace std;

struct Node
{
    int val;
    Node * left;
    Node * right;
};

Node * recurse(Node * node, int val)
{
    if (node == NULL || node->val == val)
        return node;
    if (node->val < val)
        return recurse(node->right, val);
    return recurse(node->left, val);
}

bool exists(Node * node, int val)
{
    Node * ans = recurse(node, val);
    if (ans == NULL)
        return false;
    return (ans->val == val);
}

TreeNode * lowestCommonAncestor(TreeNode * root, TreeNode * p, TreeNode * q)
{
    if (root == NULL)
        return NULL;

    if (root == p || root == q)
        return root;

    TreeNode * left = lowestCommonAncestor(root->left, p, q);
    TreeNode * right = lowestCommonAncestor(root->right, p, q);

    if (left != NULL && right != NULL)
        return root;

    if (left == NULL && right == NULL)
        return NULL;

    return left != NULL ? left : right;
}

int main() {}