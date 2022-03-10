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
    long long int count=1,sum=0;
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) 
    {
        ListNode *head=NULL,*prev=NULL;  
        if(l1==NULL)
            return l2;
        if(l2==NULL)
            return l1;
        int carry=0;
        while(l1!=NULL && l2!=NULL)
        {
            ListNode *curr=new ListNode((carry+l1->val+l2->val)%10);
            if(carry+l1->val+l2->val>=10)
                carry=1;
            else
                carry=0;
            if(head==NULL)
            {
                head=curr;
                prev=curr;
            }
            else
            {
                prev->next=curr;
                prev=curr;
            }
            l1=l1->next;
            l2=l2->next;
        }
        if(l2!=NULL)
            l1=l2;
        while(l1!=NULL)
        {
            ListNode *curr=new ListNode((carry+l1->val)%10);
            if(carry+l1->val>=10)
                carry=1;
            else
                carry=0;
            if(head==NULL)
            {
                head=curr;
                prev=curr;
            }
            else
            {
                prev->next=curr;
                prev=curr;
            }
            l1=l1->next;
        }
        if(carry==1)
        {
            ListNode *curr=new ListNode(carry);
            prev->next=curr;
        }
        return head;
    }
};
