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
    vector<int> largestValues(TreeNode* root) 
    {
        vector <int> v;
        queue<TreeNode *> q;
        if(root==NULL)    
            return v;
        q.push(root);
        q.push(NULL);
        int high=INT_MIN;
        while(q.size()>1)
        {
            TreeNode *curr=q.front();
            q.pop();
            if(curr==NULL)
            {
                q.push(NULL);
                v.push_back(high);
                high=INT_MIN;
            }
            else
            {
                high=max(high,curr->val);
                if(curr->left!=NULL)
                    q.push(curr->left);
                if(curr->right!=NULL)
                    q.push(curr->right);
            }
        }
        v.push_back(high);
        return v;
    }
};