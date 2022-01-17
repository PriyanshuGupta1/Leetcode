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
    ListNode* swapPairs(ListNode* head) 
    {
        ListNode *curr=head,*prev1=NULL,*prev2=NULL,*temp;
        if(head==NULL)
            return head;
        while(curr!=NULL && curr->next!=NULL)
        {
            if(curr==head)
                head=curr->next;
            prev2=curr->next;
            temp=curr->next->next;
            curr->next->next=curr;
            if(prev1!=NULL)
                prev1->next=prev2;
            prev1=curr;
            curr->next=temp;
            curr=curr->next;
        }
        curr=head;
        while(curr!=NULL)
        {
            cout<<curr->val<<" ";
            curr=curr->next;            
        }
        return head;
    }
};
