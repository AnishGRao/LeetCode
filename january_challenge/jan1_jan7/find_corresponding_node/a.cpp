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


Node * Search(Node *temp, Node * val, Node *cloner)
{
    if (temp == NULL)
                    return NULL;
    if(temp == val){
                    return cloner;
                            
    }
    //Null coalescing operator in gcc, allows me to use null values, but immediately switch to rhs if it resolves to null.
    return Search(temp->left,val, cloner->left) ?: Search(temp->right,val, cloner->right);                    
}

Node* getTargetCopy(Node* original, Node* cloned, Node* target) {
            return Search(original, target, cloned);               
}

int main() {
    return 0;
}
