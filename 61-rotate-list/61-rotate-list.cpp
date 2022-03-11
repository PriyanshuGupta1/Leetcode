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
    // Time Complexity: O(N)
    // Space Complexity: O(1)
    ListNode* rotateRight(ListNode* head, int k) 
    {
        if(head == NULL || head->next == NULL)    
            return head;
        int len = 1;
        ListNode *curr = head;
        for(;curr->next != NULL; len++) // calculating the length of the list
            curr = curr->next;
        curr->next = head;// forming a ring by connecting it with the head
        k=k%len;// for high value of k it will be shortened by taking mod
        for(int i = 0 ;i <= len-k-1 ; i++)
            curr = curr->next; // traversing to n-k-1 which will be the new last node
        head = curr->next; // the new head of the list
        curr->next = NULL; // the last node
        return head;
    }
};
    // Time Complexity: O(N*k)
    // Space Complexity: O(1)
    // ListNode* rotateRight(ListNode* head, int k) 
    // {
    //     if(head==NULL || head->next==NULL)    
    //         return head;
    //     int len=0;
    //     ListNode *curr=head;
    //     for(;curr!=NULL;len++)
    //         curr=curr->next;
    //     k%=len;
    //     curr=head;
    //     while(k--)
    //     {
    //         ListNode *prev=NULL;
    //         while(curr->next!=NULL)
    //         {
    //             prev=curr;
    //             curr=curr->next;
    //         }
    //         curr->next=head;
    //         head=prev->next;
    //         prev->next=NULL;
    //     }
    //     return head;
    // }
