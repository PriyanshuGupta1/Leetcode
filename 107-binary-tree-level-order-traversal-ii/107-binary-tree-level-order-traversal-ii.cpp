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
    vector<vector<int>> levelOrderBottom(TreeNode* root) 
    {
        vector <vector <int >> a;
        if(root==NULL)
            return a;
        queue <TreeNode *> q;
        q.push(root);
        while(!q.empty())
        {
            vector <int> w;
            int size=q.size();
            for(int i=0;i<size;i++)
            {
                TreeNode *curr=q.front();
                w.push_back(curr->val);
                q.pop();
                if(curr->left!=NULL)
                    q.push(curr->left);
                if(curr->right!=NULL)
                    q.push(curr->right);
            }
            a.insert(a.begin(),w);
        }
        return a;
    }
};