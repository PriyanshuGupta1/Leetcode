/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    bool hasCycle(ListNode *head) 
    {
        if(head==NULL)
            return false;
        ListNode *fast=head->next,*slow=head;
        while(fast!=NULL && slow!=NULL && fast->next!=NULL)
        {
            if(fast==slow)
                return true;
            fast=fast->next->next;
            slow=slow->next;
        }
        return false;
    }
};