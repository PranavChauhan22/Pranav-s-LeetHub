class Solution {
public:
    int rob(vector<int>& nums) {
        vector<pair<int,int>> dp(nums.size());
        dp[0]=make_pair(0,nums[0]);
        for(int i=1;i<nums.size();i++){
           dp[i].first=max(dp[i-1].first,dp[i-1].second);
        dp[i].second=dp[i-1].first+nums[i];
        }
        return max(dp[nums.size()-1].first,dp[nums.size()-1].second);
        
        
    }
};