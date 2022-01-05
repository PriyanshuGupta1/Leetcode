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
    int diameter;
public:
    int diameterOfBinaryTree(TreeNode* root) 
    {
        if(root==NULL)    
            return 0;
        int h=height(root);
        return diameter;
    }
    int height(TreeNode *root)
    {
        if(root==NULL)    
            return 0;
        int lh=height(root->left);
        int rh=height(root->right);
        diameter=max(diameter,lh+rh);
        return max(lh,rh)+1;
    }
};