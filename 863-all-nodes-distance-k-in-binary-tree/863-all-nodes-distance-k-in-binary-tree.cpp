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
    bool getPath(TreeNode* root,TreeNode* a,vector<TreeNode*> &ans){
        if(root==NULL){
            return false;
        }
        if(root==a){
            ans.push_back(root);
            return true;
        }
        bool l=getPath(root->left,a,ans);
        if(l){
            ans.push_back(root);
            return true;
        }
        bool r=getPath(root->right,a,ans);
        if(r){
            ans.push_back(root);
            return true;
        }
        return false;
    }
    void func(TreeNode* node,int k,TreeNode* b,vector<int>&v){
        if(node==NULL||node==b){
            return;
        }
        if(k==0){
            v.push_back(node->val);
            return;
        }
        func(node->left,k-1,b,v);
        func(node->right,k-1,b,v);
        
    }
    vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {
        vector<TreeNode*> ans;
        
        getPath(root,target,ans);
       
        vector<int>v;
        for(int i=0;i<ans.size()&&i<=k;i++)
        {
            func(ans[i],k-i,(i==0?NULL:ans[i-1]),v);
        }
        return v;
    }
};