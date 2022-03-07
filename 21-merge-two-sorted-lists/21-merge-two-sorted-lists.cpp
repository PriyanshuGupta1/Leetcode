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
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) 
    {
        ListNode *curr=NULL,*start=NULL;
        if(list1==NULL)
            return list2;
        else if(list2==NULL)
            return list1;
        while(list1!=NULL && list2!=NULL)
        {
            ListNode *q=new ListNode();
            if(list1->val>list2->val)
            {
                q->val=list2->val;
                list2=list2->next;
            }
            else if(list1->val<=list2->val)
            {
                q->val=list1->val;
                list1=list1->next;
            }
            if(curr==NULL)
            {
                start=q;
                curr=q;
            }
            else
            {
                curr->next=q;
                curr=curr->next;
            }
        }
        while(list1!=NULL)
        {
            ListNode *q=new ListNode(list1->val);
            if(curr==NULL)
            {
                start=q;
                curr=q;
            }
            else
            {
                curr->next=q;
                curr=curr->next;
            }
            list1=list1->next;
        }
        while(list2!=NULL)
        {
            ListNode *q=new ListNode(list2->val);
            if(curr==NULL)
            {
                start=q;
                curr=q;
            }
            else
            {
                curr->next=q;
                curr=curr->next;
            }
            list2=list2->next;
        }
        return start;
    }
};