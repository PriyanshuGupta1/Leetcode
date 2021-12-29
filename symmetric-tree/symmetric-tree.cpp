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
    public:
    bool isSymmetric(TreeNode* root) 
    {
        if(root==NULL)
            return false;
        if(root->left!=NULL && root->right!=NULL)
        {
            return preorder(root->left,root->right);
        }
        else if(root->left==NULL && root->right==NULL)
            return true;
        else
            return false;
        return true;
    }
    bool preorder(TreeNode* root,TreeNode *root1)
    {
        if(root==NULL && root1==NULL)return true;
        else if((root==NULL && root1!=NULL ) || (root!=NULL && root1==NULL))
            return false;
        else if(root->val!=root1->val)
            return false; 
        return preorder(root->left,root1->right) && preorder(root->right,root1->left);
    }
};

