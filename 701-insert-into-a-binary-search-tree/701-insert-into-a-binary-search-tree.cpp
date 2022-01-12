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
    TreeNode* insertIntoBST(TreeNode* root, int val) 
    {
        TreeNode * curr=new TreeNode(val);
        if(root==NULL)    
            return curr;
        bst(root,curr);
        return root;
        
    }
    void bst(TreeNode *root,TreeNode *curr)
    {
        if(root->left==NULL && root->val>curr->val)
        {
                root->left=curr;
        }
        else if(root->right==NULL && root->val<curr->val)
            root->right=curr;
        else if(curr->val>root->val)
            bst(root->right,curr);
        else if(curr->val<root->val)
            bst(root->left,curr);
        return;
        
    }
};