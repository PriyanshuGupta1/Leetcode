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
    int sumOfLeftLeaves(TreeNode* root) {
        if(root==NULL || root->left==NULL && root->right==NULL)
            return 0;
        return dfs(root,0);
    }
    int dfs(TreeNode *root,int flag)
    {
        if(root==NULL)
            return 0;
        if(flag==0 && root->left==NULL && root->right==NULL)
            return root->val;
        int l=0,r=0;
        if(root->left!=NULL)
            l=dfs(root->left,0);
        if(root->right!=NULL)
            r=dfs(root->right,1);
        return l+r;
    }
};