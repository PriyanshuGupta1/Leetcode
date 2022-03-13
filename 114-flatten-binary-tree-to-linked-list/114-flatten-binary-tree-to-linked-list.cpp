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
    void flatten(TreeNode* root) 
    {
        if(root==NULL)
            return;
        stack <TreeNode *> st;
        st.push(root);
        while(!st.empty())
        {
            TreeNode *curr=st.top();
            st.pop();
            if(curr->right!=NULL)
                st.push(curr->right);
            if(curr->left!=NULL)
                st.push(curr->left);
            if(st.size()>=1)
                curr->right=st.top();
            curr->left=NULL;
        }
    }
};
//     Recursive Solution
//     Time Complexity: O(N)
//     Space Complexity: O(H) :(height is max height of binary tree)
//     TreeNode *prev=NULL;
//     void flatten(TreeNode* root) 
//     {
//         if(root==NULL)
//             return;
//         flatten(root->right);
//         flatten(root->left);
//         root->right=prev;
//         root->left=NULL;
//         prev=root;
//     }
//Similar question but making the right pointer as NULL and left pointer as according to preorder traversal
//     void flatten(TreeNode* root) 
//     {
//         if(root==NULL)
//             return;
//         flatten(root->right);
//         flatten(root->left);
//         root->left=prev;
//         root->right=NULL;
//         prev=root;
//     }