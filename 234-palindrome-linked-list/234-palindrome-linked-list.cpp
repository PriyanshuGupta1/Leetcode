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
    bool isPalindrome(ListNode* head) {
        string num;
        while(head!=NULL)
        {
            num+=head->val;
            head=head->next;
        }
        string t=num;
        reverse(t.begin(),t.end());
        return num==t;
    }
};