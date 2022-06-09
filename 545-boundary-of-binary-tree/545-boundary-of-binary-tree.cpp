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
    bool isLeaf(TreeNode *root)
    {
        if(root->left==NULL && root->right==NULL)
            return true;
        else 
            return false;
    }
    void leftBoundary(TreeNode *root,vector <int> &v)
    {
        TreeNode *curr=root->left;
        while(curr)
        {
            if(!isLeaf(curr))
                v.push_back(curr->val);
            if(curr->left)
                curr=curr->left;
            else 
                curr=curr->right;
        }
    }
    void leafInorder(TreeNode *root,vector <int> &v)
    {
        if(isLeaf(root))
        {
            v.push_back(root->val);
            return;
        }
        if(root->left)
            leafInorder(root->left,v);
        if(root->right)
            leafInorder(root->right,v);
    
    }
    void rightBoundary(TreeNode * root,vector <int> &v)
    {
        vector <int> rev;
        TreeNode *curr=root->right;
        while(curr)
        {
            if(!isLeaf(curr))
                rev.push_back(curr->val);
            if(curr->right)
                curr=curr->right;
            else
                curr=curr->left;
        }
        reverse(rev.begin(),rev.end());
        for(int i=0;i<rev.size();i++)
            v.push_back(rev[i]);
    }
    vector<int> boundaryOfBinaryTree(TreeNode* root) {
        vector <int> v;
        if(root==NULL)return v;
        if(!isLeaf(root))
            v.push_back(root->val);
        leftBoundary(root,v);
        for(auto it:v)
            cout<<it<<" ";
        leafInorder(root,v);
        for(auto it:v)
            cout<<it<<" ";
        
        rightBoundary(root,v);
        for(auto it:v)
            cout<<it<<" ";
        cout<<endl;
        return v;
    }
};