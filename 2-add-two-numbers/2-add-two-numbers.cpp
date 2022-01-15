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
        int carry=0,sum=0;
        while(l1!=NULL || l2!=NULL)
        {
            if(l1!=NULL)
            {
                sum+=l1->val;
                l1=l1->next;
            }   
            if(l2!=NULL)
            {
                sum+=l2->val;
                l2=l2->next;
            }
            sum+=carry;
            carry=sum/10;
            ListNode *curr=new ListNode(sum%10);
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
            sum=0;
        }
        if(carry==1)
        {
            ListNode *curr1=new ListNode(carry);
            prev->next=curr1;
        }
        return head;
    }
};
