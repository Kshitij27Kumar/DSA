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
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        int pre=preorder.size(), in=inorder.size();
        if(pre!=in)
            return NULL;
        map<int,int>mp;
        for(int i=0;i<in;i++){
            mp[inorder[i]]=i;
        }
        return helper(preorder,0,pre-1,inorder,0,in-1,mp);
    }
    TreeNode* helper(vector<int>&preorder,int ps,int pe, vector<int>&inorder, int is, int ie, map<int,int>&mp){
        if(ps>pe || is>ie)
            return NULL;
        TreeNode* root=new TreeNode(preorder[ps]);
        int inRoot=mp[preorder[ps]];
        int leftNum=inRoot-is;
        root->left=helper(preorder,ps+1,ps+leftNum,inorder,is,inRoot-1,mp);
        root->right=helper(preorder,ps+leftNum+1,pe,inorder,inRoot+1,ie,mp);
        return root;
    }
};
