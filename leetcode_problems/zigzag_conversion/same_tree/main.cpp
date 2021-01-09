#include <atomic>
#include <bits/stdc++.h>
#include <pthread.h>

struct TreeNode
{
    int val;
    TreeNode * left;
    TreeNode * right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode * left, TreeNode * right) : val(x), left(left), right(right) {}
};

bool isSameTree(TreeNode * p, TreeNode * q)
{
    auto c1 = p, c2 = q, c3 = p, c4 = q;
    while (!(c1 == nullptr & c2 == nullptr & c3 == nullptr & c4 == nullptr))
    {
        if ((c1 != nullptr && c2 != nullptr) && c1->val == c2->val)
        {
            c1 = c1->left;
            c2 = c2->left;
        }
        else if ((c1 == nullptr ^ c2 == nullptr) | (!(c1 == nullptr | c2 == nullptr) && (c1->val != c2->val)))
            return false;
        if ((c3 != nullptr && c4 != nullptr) && c3->val == c4->val)
        {
            c3 = c3->right;
            c4 = c4->right;
        }
        else if ((c3 == nullptr ^ c4 == nullptr) | (!(c3 == nullptr | c4 == nullptr) & (c3->val != c4->val)))
            return false;
    }
    return true;
}
int main() {}
