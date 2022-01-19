class Solution {
public:
    int countSquares(vector<vector<int>>& matrix) {
        vector<vector<int>>dp(matrix.size(),vector<int>(matrix[0].size(),0));
        for(int i=matrix.size()-1;i>=0;i--){
            for(int j=matrix[0].size()-1;j>=0;j--){
                if(matrix[i][j]==1){
                    if(i==matrix.size()-1){
                        dp[i][j]=1;
                    }else if(j==matrix[0].size()-1){
                        dp[i][j]=1;
                    }else{
                        dp[i][j]=min(dp[i+1][j+1],min(dp[i][j+1],dp[i+1][j]))+1;
                    }
                }
            }
        }
        int ans=0;
       for(int i=matrix.size()-1;i>=0;i--){
            for(int j=matrix[0].size()-1;j>=0;j--){
                ans+=dp[i][j];
            }
       }
        return ans;
    }
};

