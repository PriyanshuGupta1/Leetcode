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
    vector<int> rightSideView(TreeNode* root) 
    {
        queue < TreeNode* > q;
        vector < int > v;
        if(root==NULL)
            return v;
        q.push(root);
        q.push(NULL);
        while(q.size()>1)
        {
            TreeNode* curr=q.front();
            q.pop();
            if(curr==NULL)
                q.push(NULL);
            if(q.front()==NULL)
                v.push_back(curr->val);
            if(curr!=NULL && curr->left!=NULL) q.push(curr->left);
            if(curr!=NULL && curr->right!=NULL) q.push(curr->right);
        }
        return v;
            
    }
};