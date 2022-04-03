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
        int wr;
        int wir;
        Pair(int _wr,int _wir){
            wr=_wr;
            wir=_wir;
        }
    };
    Pair func(TreeNode* root){
        if(root==NULL){
            struct Pair p(0,0);
            return p;
        }
        struct Pair l=func(root->left);
        struct Pair r=func(root->right);
        struct Pair ans(0,0);
        ans.wr=l.wir+r.wir+root->val;
        ans.wir=max(l.wr,l.wir)+max(r.wr,r.wir);
        return ans;
        
    }
    int rob(TreeNode* root) {
        struct Pair ans=func(root);
        return max(ans.wr,ans.wir);
    }
};