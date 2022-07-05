class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        vector<int> ans(nums.size(),1);
        vector<int> pre(nums.size());
        pre[0]=nums[0];
        for(int i=1;i<nums.size();i++){
            pre[i]=pre[i-1]*nums[i];
        }
        int a=1;
        for(int i=nums.size()-1;i>=1;i--){
            ans[i]=a*pre[i-1];
            a*=nums[i];
        }
        ans[0]=a;
        return ans;
    }
};