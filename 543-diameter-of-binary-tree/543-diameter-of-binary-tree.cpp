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
    struct Pair{
        int h;
        int d;
        Pair(int _h,int _d){
            h=_h;
            d=_d;
        }
    };
    Pair func(TreeNode* root){
        if(root==NULL){
            struct Pair p(-1,0);
            return p;
        }
        struct Pair l=func(root->left);
        struct Pair r=func(root->right);
        struct Pair ans(-1,-1);
        ans.h=max(l.h,r.h)+1;
        ans.d=max(l.h+r.h+2,max(l.d,r.d));
        return ans;
    }
    
    int diameterOfBinaryTree(TreeNode* root) {
        return func(root).d;
    }
};