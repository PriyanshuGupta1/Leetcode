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
    vector <int> recursion(TreeNode *root)
    {
        if(root == NULL)
            return {0,0};
        vector <int> left = recursion(root->left);
        vector <int> right =recursion(root->right);
        int rob=root->val+left[1]+right[1];
        int notRob=max(left[0],left[1])+max(right[0],right[1]);
        return {rob,notRob};
    }
    int rob(TreeNode* root) {
        vector <int> ans=recursion(root);
        return max(ans[0],ans[1]);
    }
};