class Solution {
public:
    ListNode *detectCycle(ListNode *head) 
    {
        if(head==NULL) 
            return NULL;
        ListNode *slow=head,*fast=head;
        do
        {
            slow = slow->next;
            if(slow==NULL)
                break;
            fast=fast->next;
            if(fast==NULL)
                break;
            fast=fast->next;
            if(fast==NULL)
                break;            
        }while(slow!=fast);
        if(!slow or !fast)
            return NULL;
        fast=head;
        while(fast !=slow)
            fast=fast->next,slow=slow->next;
        return fast;
    }
};