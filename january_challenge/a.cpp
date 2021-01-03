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

int main() {}