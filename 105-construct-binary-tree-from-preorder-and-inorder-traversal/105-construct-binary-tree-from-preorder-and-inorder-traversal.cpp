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
    TreeNode * build(vector <int> &preorder,vector <int> &inorder,int startIn,int endIn,int startPre,int endPre)
    {
        if(startPre>endPre || startIn>endIn )
            return NULL;
        // cout<<startIn<<" "<<endIn<<" "<<startPre<<" "<<endPre<<endl;
        TreeNode *root=new TreeNode(preorder[startPre]);
        int rt=preorder[startPre],i;
        // cout<<root->val<<" ";
        for(i=startIn;i<=endIn;i++)
        {
            if(rt==inorder[i])
                break;
        }
        // cout<<"rt"<<i<<endl;
        root->left=build(preorder,inorder,startIn,i-1,startPre+1,startPre+i-startIn);
        root->right=build(preorder,inorder,i+1,endIn,startPre+i-startIn+1,endPre);
        return root;
    }
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        return build(preorder,inorder,0,inorder.size()-1,0,preorder.size()-1);
    }
};