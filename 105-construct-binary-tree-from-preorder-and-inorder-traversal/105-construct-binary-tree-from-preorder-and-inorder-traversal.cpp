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
    TreeNode* recursion(int lIndex,int rIndex,int preS,int preE,vector <int> &preorder,vector <int> &inorder)
    {
        TreeNode* root=NULL;
        // cout<<lIndex<<" "<<rIndex<<" "<<preS <<" "<<preE<<endl;
        if(lIndex>rIndex || preS>preE)
            return NULL;
        for(int i=lIndex;i<=rIndex;i++)
        {
            if(inorder[i]==preorder[preS])
            {
                root=new TreeNode(preorder[preS]);
                root->left=recursion(lIndex,i-1,preS+1,preS+i-lIndex,preorder,inorder);
                root->right=recursion(i+1,rIndex,preS+i-lIndex+1,preE,preorder,inorder);
                return root;
            }
        }
        return NULL;
    }
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        TreeNode *root=NULL;
        if(inorder.size()==0)
            return root;
        int lIndex=0,rIndex=inorder.size(),preIndex=0;
        for(int i=0;i<inorder.size();i++)
        {
            if(inorder[i]==preorder[0])
            {
                root=new TreeNode(inorder[i]);
                root->left=recursion(lIndex,i-1,1,i-lIndex,preorder,inorder);
                root->right=recursion(i+1,rIndex,i-lIndex+1,preorder.size()-1,preorder,inorder);
                break;
            }
        }
        return root;
    }
};