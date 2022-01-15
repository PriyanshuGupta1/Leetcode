/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    bool isEvenOddTree(TreeNode* root) 
    {
        if(root==NULL)    
            return false;
        queue <TreeNode *> q;
        q.push(root);
        q.push(NULL);
        int level=0,prev=INT_MIN;
        while(q.size()>1)
        {
            TreeNode *curr=q.front();
            q.pop();
            if(curr!=NULL)
            {
                if(level&1)
                {
                    if(curr->val%2!=0)
                    {
                        cout<<"a";
                        return false;  
                    }
                }   
                else
                {
                    if(curr->val%2==0 )
                    {
                        cout<<"b";
                        return false;
                    }
                }
                if(curr->val>=prev && level%2!=0)
                {
                    cout<<curr->val<<" "<<prev<<" "<<level;
                    cout<<"c";
                    return false;
                }
                if(curr->val<=prev && level%2==0)
                {
                    cout<<curr->val<<" "<<prev;
                    return false;
                }
                prev=curr->val;
            }
            if(curr==NULL)
            {
                level++;
                if(level&1)
                    prev=INT_MAX;
                else
                    prev=INT_MIN;
                q.push(NULL);
                
            }
            if(curr!=NULL && curr->left!=NULL)
                q.push(curr->left);
            if(curr!=NULL && curr->right!=NULL)
                q.push(curr->right);                
        }
        return true;
    }
};