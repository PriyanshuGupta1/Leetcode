/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* prev;
    Node* next;
    Node* child;
};
*/

class Solution {
public:
    Node* flatten(Node* head) {
        if(head==NULL)
            return head;
        Node *curr=head;
        while(curr!=NULL)
        {
            if(curr->child!=NULL)
            {
                Node *prev1=curr->next;
                Node *curr1=curr->child;
                curr->child=NULL;
                curr1->prev=curr;
                curr->next=curr1;
                while(curr1->next!=NULL)
                    curr1=curr1->next;
                curr1->next=prev1;
                if(prev1!=NULL)
                    prev1->prev=curr1;
            }
            curr=curr->next;
        }
        return head;
    }
};