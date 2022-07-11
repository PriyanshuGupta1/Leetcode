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
    void recursion(TreeNode *root,string t,string &res)
    {
        if(root==NULL)
            return ;
        t=string(1,root->val+'a')+t;
        if(root->left==NULL && root->right==NULL)
        {
            if(t<res)
                res=t;
        }
        recursion(root->left,t,res);
        recursion(root->right,t,res);
    }
    string smallestFromLeaf(TreeNode* root) {
        string t,res="~";
        if(root==NULL)
            return NULL;
        recursion(root,t,res);
        return res;
    }
};