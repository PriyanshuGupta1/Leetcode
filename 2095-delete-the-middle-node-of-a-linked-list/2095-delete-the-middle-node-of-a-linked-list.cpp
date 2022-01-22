/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* deleteMiddle(ListNode* head) 
    {
        ListNode *slow=head,*fast=head;
        while(fast!=NULL &&fast->next!=NULL)
        {
            fast=fast->next->next;
            slow=slow->next;
        }
        if(slow==head)
            return slow->next;
        else
        {
            ListNode *curr=head;
            while(curr->next!=slow)
                curr=curr->next;
            curr->next=slow->next;
        }
        return head;
    }
};