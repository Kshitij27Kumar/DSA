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
    void inorder(TreeNode* root, int &ans, int &pre){
        if(!root)
            return;
        inorder(root->left,ans,pre);
        if(pre!=-1){
            ans=min(ans,root->val-pre);
        }
        pre=root->val;
        inorder(root->right, ans, pre);
    }
    int getMinimumDifference(TreeNode* root) {
        int ans=INT_MAX,pre=-1;
        inorder(root,ans,pre);
        return ans;
    }
};
