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
    TreeNode * build(vector <int> &preorder,vector <int> &inorder,int startIn,int endIn,int startPre,int endPre,map <int,int> &mp)
    {
        if(startPre>endPre || startIn>endIn )
            return NULL;
        // cout<<startIn<<" "<<endIn<<" "<<startPre<<" "<<endPre<<endl;
        TreeNode *root=new TreeNode(preorder[startPre]);
        int i=mp[root->val];
        root->left=build(preorder,inorder,startIn,i-1,startPre+1,startPre+i-startIn,mp);
        root->right=build(preorder,inorder,i+1,endIn,startPre+i-startIn+1,endPre,mp);
        return root;
    }
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        map <int,int> mp;
        for(int i=0;i<inorder.size();i++)
        {
            mp[inorder[i]]=i;
        }
        return build(preorder,inorder,0,inorder.size()-1,0,preorder.size()-1,mp);
    }
};