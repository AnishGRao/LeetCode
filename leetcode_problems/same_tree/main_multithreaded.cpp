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

pthread_mutex_t lock;

bool FAIL = false;

int current_data;
bool data_inputted = false;

void * traversal(void * root)
{
    std::stack<TreeNode *> _stack;
    TreeNode * _current = static_cast<TreeNode *>(root);

    while (_current != nullptr || !_stack.empty())
    {
        while (_current != nullptr)
        {
            _stack.push(_current);
            _current = _current->left;
        }
        _current = _stack.top();
        _stack.pop();
        pthread_mutex_lock(&lock);
        if (!data_inputted)
        {
            current_data = _current->val;
            data_inputted = true;
        }
        else
        {
            if (_current->val != current_data)
            {
                FAIL = true;
                return nullptr;
            }
            else
            {
                data_inputted = false;
            }
        }
        pthread_mutex_unlock(&lock);
    }
    return nullptr;
}

bool isSameTree(TreeNode * p, TreeNode * q)
{
    pthread_t _n1;
    pthread_t _n2;
    pthread_mutex_init(&lock, NULL);
    pthread_create(&_n1, NULL, &traversal, (void *)(p));
    pthread_create(&_n2, NULL, &traversal, (void *)(q));
    pthread_join(_n1, NULL);
    pthread_join(_n2, NULL);
    return !FAIL;
}

int main() {}
