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
    int dfs(TreeNode *root,int count)
    {
        if(root==NULL)
            return 0;
        int left_seq=0,right_seq=0;
        if(root->left!=NULL)
        {
            if(root->left->val-root->val==1)
                left_seq=dfs(root->left,count+1);
            else
                left_seq=dfs(root->left,1);
        } 
        if(root->right!=NULL)
        {
            if(root->right->val-root->val==1)
                right_seq=dfs(root->right,count+1);
            else
                right_seq=dfs(root->right,1);
        }
        return max(max(left_seq,right_seq),count);
    }
    int longestConsecutive(TreeNode* root) 
    {
        int count1=dfs(root,1);
        return count1;
    }
};