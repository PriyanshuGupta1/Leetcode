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
    ListNode* mergeNodes(ListNode* head) 
    {
        ListNode* start=NULL,*newn=NULL;
        if(head==NULL)
            return start;
        int sum=0;
        head=head->next;
        while(head!=NULL)
        {
            if(head->val!=0)
                sum+=head->val;
            else
            {
                ListNode * curr= new ListNode(sum);
                if(start==NULL)
                {
                    start=curr;
                    newn=curr;
                }
                else
                {
                    newn->next=curr;
                    newn=newn->next;
                }
                sum=0;
            }
            head=head->next;
        }
        return start;
    }
};