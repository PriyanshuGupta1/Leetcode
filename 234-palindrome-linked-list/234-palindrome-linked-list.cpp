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
    ListNode *front;
    bool res=true;
    void recursion(ListNode *curr)
    {
        if(curr == NULL)
            return;
        recursion(curr->next);
        if( curr->val != front->val)
            res=false;
        front=front->next;
    }
    bool isPalindrome(ListNode* head) {
        if(head == NULL)
            return true;
        front=head;
        recursion(head);
        return res;
    }
};