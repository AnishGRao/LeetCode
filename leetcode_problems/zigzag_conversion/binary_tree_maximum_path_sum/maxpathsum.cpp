#include <bits/stdc++.h>
using namespace std;
struct TreeNode
{
    int val;
    TreeNode * left;
    TreeNode * right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode * left, TreeNode * right) : val(x), left(left), right(right) {}
};

// there are cases of branches that mut be excised

// e.g.
/*

                    1
                -2      2
                you dont take left path
            need to look at before and after
            if before <0, dont use it
            if after <0 dont use it
            if everythhing <0, find greatest single node
*/
int M = -99999;
int G(TreeNode * R)
{
    if (!R)
        return 0;
    auto l = max(G(R->left), 0), r = max(G(R->right), 0), n = R->val + l + r;
    M = max(M, n);
    return max(l, r) + R->val;
}
int maxPathSum(TreeNode * root)
{
    G(root);
    return M;
}

int main() {}