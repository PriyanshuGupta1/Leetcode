/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {
        vector <int> v;
        if(root==NULL) return v;
        queue <TreeNode*> q;
        unordered_map<TreeNode *,TreeNode *> mp;
        q.push(root);
        
        while(!q.empty())
        {
            int size=q.size();
            for(int i=0;i<size;i++)
            {
                TreeNode *curr=q.front();
                q.pop();
                if(curr->left)
                {
                    q.push(curr->left);
                    mp[curr->left]=curr;
                }
                if(curr->right)
                {
                    q.push(curr->right);
                    mp[curr->right]=curr;
                }
            }
        }
        q.push(target);
        unordered_map <TreeNode *,bool> visited;
        visited[target]=true;
        int dis=0;
        while(!q.empty())
        {
            int size=q.size();

            if(dis++==k)
            {
                while(!q.empty())
                {
                    v.push_back(q.front()->val);
                    q.pop();
                }
                break;
            }
            for(int i=0;i<size;i++)
            {
                TreeNode *curr=q.front();
                q.pop();
                if(curr->left && !visited[curr->left])
                {
                    q.push(curr->left);
                    visited[curr->left]=true;
                }
                if(curr->right && !visited[curr->right])
                {
                    q.push(curr->right);    
                    visited[curr->right]=true;
                }
                if(mp[curr] && !visited[mp[curr]])
                {
                    q.push(mp[curr]);
                    visited[mp[curr]]=true;
                }
            }
            
        }
        return v;
    }
};