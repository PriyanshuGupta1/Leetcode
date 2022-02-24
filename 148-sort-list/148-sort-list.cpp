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
    ListNode* sortList(ListNode* head) 
    {
        vector <int> q;
        ListNode *curr=head;
        for(;curr!=NULL;curr=curr->next)
            q.push_back(curr->val);
        sort(q.begin(),q.end());
        int i=0;
        for(curr=head;curr!=NULL;curr=curr->next)
        {
            curr->val=q[i];
            i++;
        }
        return head;
    }
};