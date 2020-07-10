#include <bits/stdc++.h>
struct ListNode
{
    int val;
    ListNode * next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode * next) : val(x), next(next) {}
};

std::string numbers = "";
std::string temp = "";
int s1 = 0, s2 = 0;

ListNode * addTwoNumbers(ListNode * l1, ListNode * l2)
{

    do
    {
        numbers += std::to_string(l1.val);
        s1++;
    } while (l1->next != nullptr);
    do
    {
        numbers += std::to_string(l2->val);
        s2++;
    } while (l2->next != nullptr);
    int i = 0;
    for (i = s2 - 1; i >= 0;)
    {
        temp += std::to_string(numbers[s1 + i]);
    }
    s2 = std::stoi(temp);
    temp = "";
    for (i = s1 - 1; i >= 0;)
    {
        temp += std::to_string(numbers[i]);
    }
    s1 = std::stoi(temp);
    s1 += s2;
    temp = std::to_string(s1);
    ListNode ret(0);
    ListNode * temp = &ret;
    for (auto itr : temp)
    {
        ;
    }
}

int main(int argc, char ** argv) { ListNode l1 = }
