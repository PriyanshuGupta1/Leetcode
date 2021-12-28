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
    vector<int> inorderTraversal(TreeNode* root) 
    {
        vector <int> a;
        stack<TreeNode*> s;
        TreeNode *curr=root;
        while(curr!=NULL || s.empty()==false)
        {
            while(curr!=NULL)
            {
                s.push(curr);
                curr=curr->left;
            }
            curr=s.top();
            s.pop();
            a.push_back(curr->val);
            cout<<curr->val;
            curr=curr->right;
        }
        return a;
    }
};