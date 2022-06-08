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
    bool ans=true;
    int recursion(TreeNode * root)
    {
        if(root==NULL)
            return 0;
        int depthLeft=0,depthRight=0;
        if(root->left)
            depthLeft=1+recursion(root->left);
        if(root->right)
            depthRight=1+recursion(root->right);
        if(abs(depthLeft-depthRight)>1)
            ans=false;
        return max(depthLeft,depthRight);
    }
    bool isBalanced(TreeNode* root) {
        bool t=false;
        int a=recursion(root);
        return ans;
    }
};