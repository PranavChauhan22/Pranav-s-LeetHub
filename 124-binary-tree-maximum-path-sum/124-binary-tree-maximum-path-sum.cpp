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
           int ans=INT_MIN;
    int func(TreeNode* root){
        if(root==NULL){
            return 0;
        }
        int lh=max(0,func(root->left));
        int rh=max(0,func(root->right));
        ans=max(ans,lh+rh+root->val);
        return max(lh,rh)+root->val;
    }
    int maxPathSum(TreeNode* root) {
 
        func(root);
        return ans;
    }
};