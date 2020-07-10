#include <bits/stdc++.h>
using namespace std;
struct ListNode
{
    int val;
    ListNode * next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode * next) : val(x), next(next) {}
};

ListNode * mergeKLists(vector<ListNode *> & lists)
{
    if (lists.empty())
        return nullptr;

    auto cmp = [](ListNode * l1, ListNode * l2) { return l1->val > l2->val; };
    priority_queue<ListNode *, std::vector<ListNode *>, decltype(cmp)> _queue(cmp);
    ListNode * _head = nullptr;
    ListNode * _top;
    for (auto _list : lists)
        if (_list != nullptr)
            _queue.push(_list);

    while (!_queue.empty())
    {
        struct ListNode * _temp = _queue.top();
        _queue.pop();
        if (_temp->next != nullptr)
            _queue.push(_temp->next);

        if (_head == nullptr)
        {
            _head = _temp;
            _top = _temp;
        }
        else
        {
            _top->next = _temp;
            _top = _temp;
        }
    }
    return _head;
}
int main() { mergeKLists(lists); }