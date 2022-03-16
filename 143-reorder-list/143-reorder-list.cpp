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
    void reorderList(ListNode* head) 
    {
        if(head==NULL || head->next==NULL || head->next->next==NULL)
            return;
        ListNode * curr=head;
        while(curr!=NULL && curr->next!=NULL)
        {
            ListNode *temp=curr,*prev=NULL;
            while(temp->next!=NULL)
            {
                prev=temp;
                temp=temp->next;
            }
            prev->next=NULL;
            temp->next=curr->next;
            curr->next=temp;
            curr=curr->next->next;
        }
    }
};