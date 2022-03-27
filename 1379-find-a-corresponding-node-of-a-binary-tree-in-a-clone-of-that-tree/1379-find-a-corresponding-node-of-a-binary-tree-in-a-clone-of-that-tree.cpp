/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

class Solution {
public:
    TreeNode * path(TreeNode* root, TreeNode* cloned, TreeNode* target)
    {
        if(root==NULL)
            return NULL;
        if(target==root)
            return cloned;
        TreeNode *curr1=path(root->left,cloned->left,target);
        TreeNode *curr2=path(root->right,cloned->right,target);
        if(curr1!=NULL)
            return curr1;
        if(curr2!=NULL)
            return curr2;
        return NULL;
    }
    TreeNode* getTargetCopy(TreeNode* original, TreeNode* cloned, TreeNode* target) {
        if(original==NULL)
            return original;
        TreeNode *cloned_target=path(original,cloned,target);
        return cloned_target;
    }
};