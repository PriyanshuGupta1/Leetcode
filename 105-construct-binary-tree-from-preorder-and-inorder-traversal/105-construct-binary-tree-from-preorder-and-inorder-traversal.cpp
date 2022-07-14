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
        
        // cout<<lIndex<<" "<<rIndex<<" "<<preS <<" "<<preE<<endl;
        if(lIndex>rIndex || preS>preE)
            return NULL;
        TreeNode* root=new TreeNode(preorder[preS]);
        int i;
        for(i=lIndex;i<=rIndex;i++)
            if(inorder[i]==preorder[preS])
                break;
        root->left=recursion(lIndex,i-1,preS+1,preS+i-lIndex,preorder,inorder);
        root->right=recursion(i+1,rIndex,preS+i-lIndex+1,preE,preorder,inorder);
        return root;
    }
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        TreeNode *root=NULL;
        if(inorder.size()==0)
            return root;
        int lIndex=0,rIndex=inorder.size();

        return recursion(lIndex,rIndex,0,preorder.size()-1,preorder,inorder);
    }
};