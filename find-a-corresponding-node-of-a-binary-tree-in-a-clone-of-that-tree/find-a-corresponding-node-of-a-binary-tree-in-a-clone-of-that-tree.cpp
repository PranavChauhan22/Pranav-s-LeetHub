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
    TreeNode* ans=NULL;
    bool func(TreeNode* original, TreeNode* cloned, TreeNode* target){
        if(original==NULL){
            return false;
        }
        if(original==target){
            ans=cloned;
            return true;
        }
        bool v1=func(original->left,cloned->left,target);
        if(v1){
            return true;
        }
        bool v2=func(original->right,cloned->right,target);
        if(v2){
            return true;
        }
        return false;
    }
    TreeNode* getTargetCopy(TreeNode* original, TreeNode* cloned, TreeNode* target) {
        func(original,cloned,target);
        return ans;
    }
};