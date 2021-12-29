/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node* next;

    Node() : val(0), left(NULL), right(NULL), next(NULL) {}

    Node(int _val) : val(_val), left(NULL), right(NULL), next(NULL) {}

    Node(int _val, Node* _left, Node* _right, Node* _next)
        : val(_val), left(_left), right(_right), next(_next) {}
};
*/

class Solution {
public:
    Node* connect(Node* root) 
    {
        
        if(root==NULL) return root;
        Node *curr=new Node(NULL);
        queue <Node*> q;
        curr=root;
        q.push(root);
        q.push(NULL);
        while(q.size()>1)
        {
            Node *c=q.front();
            q.pop();
            Node *t=q.front();
            if(c==NULL)
                q.push(c);
            else
            {
                if(t==NULL)
                    c->next=NULL;
                else
                    c->next=t;
                if(c->left!=NULL) q.push(c->left);
                if(c->right!=NULL) q.push(c->right);
            }

        }
        return curr;
    }
};