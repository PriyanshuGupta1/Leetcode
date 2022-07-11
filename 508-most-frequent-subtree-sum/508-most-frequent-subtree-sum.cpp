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
    map <int,int> mp;
public:
    int inorder(TreeNode *root)
    {
        if(root==NULL)
            return 0;
        int lSum=inorder(root->left);
        int rSum=inorder(root->right);
        mp[lSum+rSum+root->val]++;
        return lSum+rSum+root->val;
    }
    vector<int> findFrequentTreeSum(TreeNode* root) {
        // we will use map to store the freq of subtrees;
        // traverse and calculate all the subtree sum
        // finally traverse the map and find the subtree with the highest frequency sum;
        vector <int> res;
        if(root==NULL)
            return res;
        int dummy=inorder(root);
        int mostFreq=0;
        for(auto it=mp.begin();it!=mp.end();it++)
        {
            if(mostFreq<it->second)
                mostFreq=it->second;
        }
        for(auto it=mp.begin();it!=mp.end();it++)
        {
            if(it->second==mostFreq)
                res.push_back(it->first);
        }
        return res;
    }
};