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
    void func(TreeNode* root,vector<int> &ans){
        if(root==NULL){
            return;
        }
        func(root->left,ans);
        ans.push_back(root->val);
        func(root->right,ans);
    }
    int minDiffInBST(TreeNode* root) {
        vector<int> ans;
        func(root,ans);
        int a=INT_MAX;
        for(int i=0;i<ans.size()-1;i++){
            a=min(a,ans[i+1]-ans[i]);
        }
        return a;
    }
};