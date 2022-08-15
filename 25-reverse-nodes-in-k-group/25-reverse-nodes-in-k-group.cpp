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
    ListNode *reverse(ListNode *head)
    {
        if(head == NULL)
            return head;
        ListNode *prev=NULL;
        while(head!=NULL)
        {
            ListNode *temp=head->next;
            head->next=prev;
            prev=head;
            head=temp;
        }
        return prev;
    }
    ListNode* reverseKGroup(ListNode* head, int k) {
        if( head == NULL)
            return head;
        ListNode *dummy=new ListNode(0);
        dummy->next=head;
        ListNode *curr=head,*prev=dummy;
        int len = 0;
        while( curr != NULL )
        {
            len++;
            if(len == k)
            {
                ListNode * temp=curr->next;
                curr->next=NULL;
                ListNode *rev=reverse(prev->next);
                prev->next=rev;
                curr=temp;
                ListNode *trav=dummy;
                while(trav->next!=NULL)
                    trav=trav->next;
                trav->next=temp;
                prev=trav;
                len=0;
            }
            else
            {
                curr=curr->next;
            }
        }
        return dummy->next;
    }
};