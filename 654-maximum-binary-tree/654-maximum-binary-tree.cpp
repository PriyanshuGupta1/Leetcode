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
    TreeNode *createTree(vector <int> &nums,int left,int right)
    {
        if(left>right)
            return NULL;
        int max=INT_MIN,index=left;
        for(int i=left;i<=right;i++)
        {
            if(nums[i]>max)
            {
                max=nums[i];
                index=i;
            }
        }
        TreeNode *curr=new TreeNode(nums[index]);
        curr->left=createTree(nums,left,index-1);
        curr->right=createTree(nums,index+1,right);
        return curr;
    }
    TreeNode* constructMaximumBinaryTree(vector<int>& nums) {
        TreeNode *root;
        root=createTree(nums,0,nums.size()-1);
        return root;
    }
};