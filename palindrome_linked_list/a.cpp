#include <bits/stdc++.h>
typedef double _d;
using namespace std;

struct Node
{
    int val;
    Node * left;
    Node * right;
    Node * next;
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

bool isPalindrome(Node * head)
{
    std::string str = "";
    while (head != NULL)
        str += head->val, head = head->next;
    std::string s = str.substr(0, str.size() / 2);
    std::reverse(s.begin(), s.end());
    return str.size() % 2 == 0 ? s == str.substr(str.size() / 2, str.size() / 2)
                               : s == str.substr((str.size() / 2) + 1, str.size() / 2);
}

int main() {}