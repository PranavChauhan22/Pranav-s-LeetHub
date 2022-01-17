class Solution {
public:
    int maxCoins(vector<int>& nums) {
        vector<vector<int>>dp(nums.size(),vector<int>(nums.size(),0));
        for(int g=0;g<nums.size();g++){
            for(int i=0,j=g;j<nums.size();i++,j++){
                int sum=INT_MIN;
                for(int k=i;k<=j;k++){
                    int l=(k==i?0:dp[i][k-1]);
                    int r=(k==j?0:dp[k+1][j]);
                    int c=(i-1>=0?nums[i-1]:1)*nums[k]*(j+1<nums.size()?nums[j+1]:1);
                    sum=max(l+r+c,sum);
                }
                dp[i][j]=sum;
            }
        }
        return dp[0][nums.size()-1];
    }
};