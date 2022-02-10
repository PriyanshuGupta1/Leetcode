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
class Solution 
{
private:
    vector <vector <int>>q;
public:
    void dfs(TreeNode *root,int targetSum,vector <int>a)
    {
        if(root==NULL)
            return;
        a.push_back(root->val);
        if(root->left==NULL && root->right==NULL)
        {
            targetSum-=root->val;
            if(targetSum==0)
            {
                q.push_back(a);
                return;
            }
            if(targetSum<0)
                return;
        }
        if(root->left!=NULL)
            dfs(root->left,targetSum-root->val,a);
        if(root->right!=NULL)
            dfs(root->right,targetSum-root->val,a);
    }
    vector<vector<int>> pathSum(TreeNode* root, int targetSum) 
    {
        vector<int> a;
        dfs(root,targetSum,a);
        return q;
    }
};