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
    ListNode* mergeKLists(vector<ListNode*>& lists) 
    {
        vector <int> a;
        if(lists.size()==0)
            return NULL;
        for(int i=0;i!=lists.size();i++)
        {
            ListNode *curr=lists[i];
            for(auto j=0;;j++)
            {
                if(curr!=NULL)
                {
                    a.push_back(curr->val);
                    curr=curr->next;
                }
                else
                    break;
            }
        }
        sort(a.begin(),a.end());
        ListNode *curr=NULL,*start=NULL;
        for(int i=0;i<a.size();i++)
        {
            ListNode *curr1=new ListNode(a[i]);
            cout<<a[i]<<" ";
            if(start==NULL)
            {
                start=curr1;
                curr=curr1;
            }
            else
            {
                curr->next=curr1;
                curr=curr1;
            }
        }
        return start;
    }
};