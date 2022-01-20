class Solution {
public:
    int jump(vector<int>& nums) {
        vector<int> dp(nums.size(),INT_MAX);
        dp[nums.size()-1]=0;
        for(int i=nums.size()-2;i>=0;i--){
            int ans=INT_MAX;
            for(int j=i+1;j<=min(int(i+nums[i]),int(nums.size()-1));j++){
                ans=min(ans,dp[j]);
            }
            if(ans!=INT_MAX){
                dp[i]=ans+1;
            }
        }

        return dp[0];
    }
};