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
private:
    int max_Val=INT_MIN;
public:
    int gain(TreeNode *root)
    {
        if(root==NULL)
            return 0;
        int lGain = max(gain(root->left),0);
        int rGain = max(gain(root->right),0);
        int price = root->val+lGain+rGain;
        max_Val=max(max_Val,price);
        return root->val+max(lGain,rGain);
    }
    int maxPathSum(TreeNode* root) 
    {
        gain(root);    
        return max_Val;
    }
};