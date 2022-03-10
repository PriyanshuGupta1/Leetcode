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
class Solution 
{
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) 
    {
        ListNode *head=new ListNode(0),*dummy=head;  
        if(l1==NULL)return l2;
        if(l2==NULL)return l1;
        int carry=0;
        while(l1!=NULL || l2!=NULL)
        {
            int x=(l1!=NULL) ? l1->val:0;
            int y=(l2!=NULL) ? l2->val:0;
            head->next=new ListNode((carry+x+y)%10);
            head=head->next;
            carry=(carry+x+y)/10;
            if(l1!=NULL) 
                l1=l1->next;
            if(l2!=NULL)
                l2=l2->next;
        }
        if(carry==1)
            head->next=new ListNode(carry);
        return dummy->next;
    }
};
