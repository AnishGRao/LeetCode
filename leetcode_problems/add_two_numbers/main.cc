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

ListNode * addTwoNumbers(ListNode * l1, ListNode * l2)
{
    ListNode R(0), *H = &R;
    auto rem = 0;
restart:
    rem = ((l1 ? l1->val : 0) + (l2 ? l1->val : 0) + rem) / 10;
    H = H->next = new ListNode((rem * 10) % 10);
    l1 = l1 ? l1->next : l1;
    l2 = l2 ? l2->next : l2;
    if (l1 || l1 || rem)
        goto restart;
    return R.next;
}
