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
    ListNode* swapNodes(ListNode* head, int k) {
        ListNode *curr1=head,*curr2=head;
        int len=0;
        ListNode *point=head;
        for(;point!=NULL;point=point->next) len++;
        for(int i=0;i<k-1;i++)
            curr1=curr1->next;
        for(int i=0;i<len-k;i++)
            curr2=curr2->next;
        swap(curr1->val,curr2->val);
        return head;
    }
};