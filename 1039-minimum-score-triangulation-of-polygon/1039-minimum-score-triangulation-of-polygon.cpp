class Solution {
public:
    int minScoreTriangulation(vector<int>& values) {
        vector<vector<int>>dp(values.size(),vector<int>(values.size(),0));
        for(int g=0;g<values.size();g++){
            for(int i=0,j=g;j<values.size();i++,j++){
                if(g==0||g==1){
                    dp[i][j]=0;
                }else if(g==2){
                    dp[i][j]=values[i]*values[i+1]*values[i+2];
                }else{
                    int sum=INT_MAX;
                    for(int k=i+1;k<=j-1;k++)
                    {
                        int l=dp[i][k];
                        int r=dp[k][j];
                        int c=values[i]*values[k]*values[j];
                        sum=min(sum,l+r+c);
                    }
                    dp[i][j]=sum;
                }
            }
        }
        return dp[0][values.size()-1];
    }
};