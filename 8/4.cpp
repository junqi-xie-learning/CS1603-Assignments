struct ListNode
{
    int val;
    ListNode *next;
};

ListNode* deleteDuplicates(ListNode *head)
{
    if (!head)
        return head;
    
    while (head->next && head->val == head->next->val)
    {
        ListNode *temp = head->next;
        head->next = head->next->next;
        delete temp;
    }
    head->next = deleteDuplicates(head->next);
    return head;
}