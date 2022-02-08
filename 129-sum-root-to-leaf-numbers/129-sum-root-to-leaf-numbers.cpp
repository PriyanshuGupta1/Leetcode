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
    int count=0;
public:
    void dfs(TreeNode *root,int value)
    {
        if(value==0)
            value=root->val;
        else
            value+=root->val;
        if(root->right==NULL && root->left==NULL)
            count+=value;
        if(root->right!=NULL)
            dfs(root->right,value*10);
        if(root->left!=NULL)
            dfs(root->left,value*10);
    }
    int sumNumbers(TreeNode* root) 
    {
        dfs(root,0);
        return count;
    }
};