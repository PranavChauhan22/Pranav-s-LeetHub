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
class FindElements {
public:
    unordered_map<int,bool> mp;
    void func(TreeNode* root){
        if(root==NULL){
            return;
        }
        mp[root->val]=true;
        if(root->left)
        {
            root->left->val=2*root->val+1;
        }
         if(root->right)
        {
            root->right->val=2*root->val+2;
        }
        func(root->left);
        func(root->right);
    }
    FindElements(TreeNode* root) {
        root->val=0;
        func(root);
        
    }
    
    bool find(int target) {
        
        return (mp.find(target)==mp.end()?false:true);
    }
};

/**
 * Your FindElements object will be instantiated and called as such:
 * FindElements* obj = new FindElements(root);
 * bool param_1 = obj->find(target);
 */