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
    TreeNode* func(vector<int>& preorder, vector<int>& postorder,int psi,int pei,int pssi,int psse){
        if(psi>pei){
            return NULL;
        }
        TreeNode* node=new TreeNode(preorder[psi]);
        if(psi==pei){
            return node;
        }
        int idx=pssi;
        while(postorder[idx]!=preorder[psi+1]){
            idx++;
        }
        int t=idx-pssi+1;
        node->left=func(preorder,postorder,psi+1,psi+t,pssi,idx);
        node->right=func(preorder,postorder,psi+t+1,pei,idx+1,psse-1);
        return node;
    }
    TreeNode* constructFromPrePost(vector<int>& preorder, vector<int>& postorder) {
        return func(preorder,postorder,0,preorder.size()-1,0,postorder.size()-1);
    }
};