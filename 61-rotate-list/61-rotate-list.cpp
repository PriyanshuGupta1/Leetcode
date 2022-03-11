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
    ListNode* rotateRight(ListNode* head, int k) 
    {
        if(head==NULL || head->next==NULL)    
            return head;
        int len=0;
        ListNode *cur=head;
        while(cur!=NULL)
        {
            cur=cur->next;
            len++;
        }
        k=k%len;
        while(k--)
        {
            ListNode *curr=head,*prev=NULL;
            while(curr->next!=NULL)
            {
                prev=curr;
                curr=curr->next;
            }
            curr->next=head;
            head=prev->next;
            prev->next=NULL;
        }
        return head;
    }
};
// 1 2 3 4 5
// k=2 1 2 3 4(prev) 5(curr)