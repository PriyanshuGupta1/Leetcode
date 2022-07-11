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
    set <string> st;
public:
    void recursion(TreeNode *root,string t)
    {
        if(root==NULL)
            return;
        // cout<<root->val;
        char curr=char(root->val+'a');
        t=curr+t;
        // cout<<t<<endl;
        if(root->left==NULL && root->right==NULL)
            st.insert(t);
        recursion(root->left,t);
        recursion(root->right,t);
    }
    string smallestFromLeaf(TreeNode* root) {
        string t;
        if(root==NULL)
            return t;
        recursion(root,t);
        auto it=st.begin();
        t=*it;
        return t;
    }
};