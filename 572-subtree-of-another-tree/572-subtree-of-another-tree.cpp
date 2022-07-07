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
    
    bool solve(TreeNode* n1,TreeNode* n2){
        if(n1==NULL&&n2==NULL){
            return true;
        }
        if(n1==NULL||n2==NULL){
            return false;
        }
        if(n1->val!=n2->val){
            return false;
        }
        return solve(n1->left,n2->left)&&solve(n1->right,n2->right);
    }
    
    
    bool isSubtree(TreeNode* root, TreeNode* subRoot) {
        if(root==NULL&&subRoot==NULL){
            return true;
        }
        if(root==NULL||subRoot==NULL){
            return false;
        }
        if(root->val==subRoot->val){
            if(solve(root,subRoot)){
                return true;   
            }
        }
        return isSubtree(root->left,subRoot) || isSubtree(root->right,subRoot);
    }
};