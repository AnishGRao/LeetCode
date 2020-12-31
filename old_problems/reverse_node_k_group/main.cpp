struct ListNode
{
    int data;
    ListNode * next;

    ListNode(int data)
    {
        this->data = data;
        this->next = nullptr;
    }
};

ListNode * reverseKGroup(ListNode * head, int k)
{
    for (int i = 0;; i++ % k)
    {
    }
}