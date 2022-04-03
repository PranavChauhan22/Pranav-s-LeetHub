/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    bool getPath(TreeNode* root,TreeNode* node,vector<TreeNode*> &v){
        if(root==node){
            v.push_back(root);
            return true;
        }
        if(root==NULL){
            return false;
        }
        bool a=getPath(root->left,node,v);
        if(a){
            v.push_back(root);return true;
        }
        bool b=getPath(root->right,node,v);
        if(b){
            v.push_back(root);return true;
        }
        return false;
    }
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        vector<TreeNode*> ans1,ans2;
        getPath(root,p,ans1);
        getPath(root,q,ans2);
        unordered_map<TreeNode*,bool> mp;
        for(auto it:ans1){
            mp[it]=true;
        }
        for(auto it:ans2){
            if(mp.find(it)!=mp.end()){
                return it;
            }
        }
        return NULL;
    }
};