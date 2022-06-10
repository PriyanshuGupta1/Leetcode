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
    
    vector<vector<int>> verticalOrder(TreeNode* root) {
        vector <vector <int>> v;
        if(root==NULL)
            return v;
        map <int,map<int,vector<int>>> mp;
        queue <pair<TreeNode*, pair<int,int>>> q;
        q.push({root,{0,0}});
        while(!q.empty())
        {
            auto p=q.front();
            q.pop();
            TreeNode *curr=p.first;
            int vertical=p.second.first;
            int depth=p.second.second;
            mp[vertical][depth].push_back(curr->val);
            if(curr->left)
                q.push({curr->left,{vertical-1,depth+1}});
            if(curr->right)
                q.push({curr->right,{vertical+1,depth+1}});
        }
        for (auto p :mp)
        {
            vector <int> col;
            for (auto w: p.second)
            {
                col.insert(col.end(),w.second.begin(),w.second.end()); 
            }
            v.push_back(col);
        }
        return v;
    }
};