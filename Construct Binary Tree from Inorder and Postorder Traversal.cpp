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
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        int in=inorder.size();
        int po=postorder.size();
        if(in!=po)
            return NULL;
        map<int,int>mp;
        for(int i=0;i<in;i++){
            mp[inorder[i]]=i;
        }
        return helper(inorder,0,in-1,postorder,0,po-1,mp);
    }
    TreeNode* helper(vector<int>&inorder, int is, int ie, vector<int>&postorder, int ps, int pe, map<int,int>&mp){
        if(ps>pe || is>ie)
            return NULL;
        TreeNode* root=new TreeNode(postorder[pe]);
        int inRoot=mp[postorder[pe]];
        int numsLeft=inRoot-is;
        root->left=helper(inorder,is, inRoot-1, postorder, ps, ps+numsLeft-1, mp);
        root->right=helper(inorder, inRoot+1, ie, postorder, ps+numsLeft,pe-1,mp);
        return root;
    }
};
