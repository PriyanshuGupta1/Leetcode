/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
public:
    Node* copyRandomList(Node* head) 
    {
        if(head==NULL)    
            return head;
        Node *dummy=new Node(0);
        Node *curr=head,*prev=dummy;
        while(curr!=NULL)
        {
            prev->next=new Node(curr->val);
            prev=prev->next;
            curr=curr->next;
        }
        curr=head,prev=dummy->next;
        while(curr!=NULL)
        {
            Node *trav=dummy->next,*find=curr->random,*t=head;;
            int len=0;
            while(trav!=NULL)
            {
                if(find!=NULL && t==find)
                {
                    prev->random=trav;
                    prev=prev->next;
                    break;
                }
                if(find==NULL)
                {
                    prev->random=NULL;
                    prev=prev->next;
                    break;
                }
                t=t->next;
                trav=trav->next;
            }
            curr=curr->next;
        }
        return dummy->next;
    }
};