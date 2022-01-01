class Solution {
public:
    int maxCoins(vector<int>& nums) {
        vector<vector<int>>dp(nums.size(),vector<int>(nums.size(),0));
        for(int g=0;g<nums.size();g++){
            for(int i=0,j=g;j<nums.size();i++,j++){

                    int ans=0;
                    for(int k=i;k<=j;k++){
                        int b=(k!=i?dp[i][k-1]:0)+(k!=j?dp[k+1][j]:0);
                        int w=(i-1>=0?nums[i-1]:1)*nums[k]*(j+1<nums.size()?nums[j+1]:1);
                        ans=max(ans,b+w);
                            
                    }
                    dp[i][j]=ans;
                
            }
        }

        return dp[0][dp.size()-1];
    }
};