/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node* parent;
};
*/

class Solution {
public:
    Node* lowestCommonAncestor(Node* p, Node * q) {
        vector <Node *> path1,path2;
        while(p!=NULL)
        {
            path1.push_back(p);
            p=p->parent;
        }
        while(q!=NULL)
        {
            path2.push_back(q);
            q=q->parent;
        }
        reverse(path1.begin(),path1.end());
        reverse(path2.begin(),path2.end());
        Node *curr=NULL;
        for(int i=0;i<min(path1.size(),path2.size());i++)
        {
            if(path1[i]==path2[i])
                curr=path1[i];
            else
                break;
        }
        return curr;
    }
};