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
    int deepestLeavesSum(TreeNode* root) 
    {
        if(root==NULL) return 0;
        queue <TreeNode *> q;
        q.push(root);
        q.push(NULL);
        int sum=0;
        while(q.size()>1)
        {
            TreeNode* curr=q.front();
            q.pop();
            if(curr==NULL)
            {
                sum=0;
                q.push(NULL);
            }
            else
            {
                sum+=curr->val;
                if(curr->left!=NULL)
                    q.push(curr->left);
                if(curr->right!=NULL)
                    q.push(curr->right);
            }
        }
        return sum;
    }
};