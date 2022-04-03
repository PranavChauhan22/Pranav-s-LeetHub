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
    void getPath(TreeNode* root,vector<string> &ans,string str){
        if(root->left==NULL&&root->right==NULL){
            ans.push_back(str);
            str="";
            return;
        }
        if(root->left){
        getPath(root->left,ans,str+"->"+to_string(root->left->val));
        }
        if(root->right){
        getPath(root->right,ans,str+"->"+to_string(root->right->val));
        }
    }
    vector<string> binaryTreePaths(TreeNode* root) {
      vector<string> ans;
        getPath(root,ans,to_string(root->val));
        return ans;
    }
};