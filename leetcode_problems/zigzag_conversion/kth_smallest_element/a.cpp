#include <bits/stdc++.h>
typedef double _d;
using namespace std;

struct Node
{
    int val;
    Node * left;
    Node * right;
    Node() : val(0), left(nullptr), right(nullptr) {}
    Node(int x) : val(x), left(nullptr), right(nullptr) {}
    Node(int x, Node * left, Node * right) : val(x), left(left), right(right) {}
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

void inorder_list_creation(Node * root, Node *& out)
{
    if (root == NULL)
        return;
    inorder_list_creation(root->left, out);
    out->left = NULL, out->right = root, out = root;
    inorder_list_creation(root->right, out);
}

int flatten_sort(Node * root, int k)
{
    Node * tempNode = new Node(-1);
    Node * ref = tempNode;
    inorder_list_creation(root, ref);
    ref->left = ref->right = NULL;
    Node * flattened = tempNode->right;
    delete tempNode;
    std::vector<int> _list;
    while (flattened->right != NULL)
    {
        _list.emplace_back(flattened->val);
        flattened = flattened->right;
    }
    _list.emplace_back(flattened->val);
    std::sort(_list.begin(), _list.end(), std::less<int>());
    return _list[k - 1];
}

int main() {}
