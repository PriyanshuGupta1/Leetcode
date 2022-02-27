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
    int widthOfBinaryTree(TreeNode* root) 
    {
        int maxCount=0;
        if(root==NULL)    
            return maxCount;
        queue <pair<TreeNode *,long long>> q;
        q.push({root,0});
        while(q.empty()!=1)
        {
            int size=q.size();
            int minEle=q.front().second;
            int first,last;
            for(int i=0;i<size;i++)
            {
                long long currId=q.front().second-minEle;
                TreeNode *curr=q.front().first;
                q.pop();
                if(i==0)
                    first=currId;
                if(i==size-1)
                    last=currId;
                if(curr->left!=NULL)
                    q.push({curr->left,2*currId+1});
                if(curr->right!=NULL)
                    q.push({curr->right,2*currId+2});
            }
            maxCount=max(maxCount,last-first+1);
        }
        return maxCount;
    }
};
