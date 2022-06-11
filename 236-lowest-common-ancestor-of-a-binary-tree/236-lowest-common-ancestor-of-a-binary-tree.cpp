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
    bool isPath(TreeNode *root,vector <TreeNode *> &arr,TreeNode *p)
    {
        if(!root)
            return false;
        arr.push_back(root);
        if(p==root)
            return true;
        if(isPath(root->left,arr,p) || isPath(root->right,arr,p))
            return true;
        arr.pop_back();
        return false;
    }
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        vector <TreeNode *> p1,q1;
        isPath(root,p1,p);
        isPath(root,q1,q);
        TreeNode *curr=NULL;
        for(int i=0;i<min(p1.size(),q1.size());i++)
        {
            if(p1[i]==q1[i])
                curr=p1[i];
            else
                break;
        }
        return curr;
    }
};