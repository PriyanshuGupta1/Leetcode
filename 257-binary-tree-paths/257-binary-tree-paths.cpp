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
    void path(TreeNode *root,vector <string> &t,string a)
    {
        if(root==NULL)
            return;
        else
        {   if(a.length()!=0)
                a+="->"+to_string(root->val);
            else
                a+=to_string(root->val); 
        }
        if(root->left==NULL && root->right==NULL)
            t.push_back(a);
        path(root->left,t,a);
        path(root->right,t,a);
            
    }
    vector<string> binaryTreePaths(TreeNode* root) {
        vector <string > t;
        if(root==NULL)
            return t;
        string a;
        path(root,t,a);
        return t;
    }
};