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
    int maxLevelSum(TreeNode* root) {
        if(root == NULL)
            return 0;
        queue <TreeNode *> q;
        q.push(root);
        int lvl=1,maxSum=INT_MIN,maxLvl=0;
        while( !q.empty() )
        {
            int size=q.size(),currSum=0;
            for(int i=0;i<size;i++)
            {
                auto top=q.front();
                q.pop();
                currSum += top->val;
                if(top->left != NULL)
                    q.push(top->left);
                if(top->right != NULL)
                    q.push(top->right);
            }
            if(maxSum<currSum)
            {
                maxLvl=lvl;
                maxSum=currSum;
            }
            lvl++;
        }
        return maxLvl;
    }
};