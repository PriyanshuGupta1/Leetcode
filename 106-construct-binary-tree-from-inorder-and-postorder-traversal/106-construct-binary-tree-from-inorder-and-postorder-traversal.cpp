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
    TreeNode *build(vector <int> &inorder,vector <int> &postorder ,int startIn,int endIn,int startPost,int endPost,map <int,int> &mp)
    {
        // cout<<startIn<<" "<<endIn<<" "<<startPost<<" "<<endPost<<endl;
        if(startIn>endIn || startPost>endPost)
            return NULL;
        TreeNode *root=new TreeNode(postorder[endPost]);
        
        int index=mp[postorder[endPost]];
        // cout<<index<<endl;
        root->right=build(inorder,postorder,index+1,endIn,endPost-(endIn-index),endPost-1,mp);
        root->left=build(inorder,postorder,startIn,index-1,startPost,endPost-(endIn-index)-1,mp);
        return root;
    }
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        if(inorder.size()==0)
            return NULL;
        map <int,int > mp;
        for(int i=0;i<inorder.size();i++)
            mp[inorder[i]]=i;
        return build(inorder,postorder,0,inorder.size()-1,0,postorder.size()-1,mp);
    }
};