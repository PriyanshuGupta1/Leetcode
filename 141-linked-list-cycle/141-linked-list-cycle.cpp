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
        ListNode *curr=head->next;
        while( head!=NULL && curr!=NULL&& curr->next!=NULL)
        {
            if(curr==head)
                return true;
            curr=curr->next->next;
            head=head->next;
            
        }
        return false;
    }
};