class Solution {
public:
    
    int dfs(int x,int y,vector<vector<bool>> vis,int m,int n,vector<vector<int>>&dp){
        if(x<0||y<0||x>=vis.size()||y>=vis[0].size()||vis[x][y]){
            return 0;
        }
        if(x==m-1&&y==n-1){
            return 1;
        }
        if(dp[x][y]!=-1){
            return dp[x][y];
        }
        vis[x][y]=true;
        int l=dfs(x+1,y,vis,m,n,dp);
        int r=dfs(x,y+1,vis,m,n,dp);
        dp[x][y]=l+r;
        return dp[x][y];
        // vis[x][y]=false;
    }
    int uniquePaths(int m, int n) {
        if(m==1&&n==1){
            return 1;
        }
        vector<vector<bool>>vis(m,vector<bool>(n,false));
        vector<vector<int>>dp(100,vector<int>(100,-1));
      dfs(0,0,vis,m,n,dp);
        return dp[0][0];
    }
};