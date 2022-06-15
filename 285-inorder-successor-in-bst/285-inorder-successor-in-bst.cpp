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
private:
    vector <TreeNode *> v;
public:
    void preorder(TreeNode *root)
    {
        if(root==NULL)
            return;
        preorder(root->left);
        v.push_back(root);
        preorder(root->right);
    }
    TreeNode* inorderSuccessor(TreeNode* root, TreeNode* p) {
        if(root==NULL)
            return NULL;
        preorder(root);
        for(int i=0;i<v.size();i++)
        {
            if(v[i]==p)
            {
                if(i+1>=v.size())
                    return NULL;
                else
                    return v[i+1];
            }
        }
        return NULL;
    }
};