class Solution {
public:
    int z=0;
    void dfs(int x,int y,vector<vector<int>>&grid){
        grid[x][y]=0;
        z++;
        int arr[4][2]={{1,0},{-1,0},{0,1},{0,-1}};
        for(int i=0;i<4;i++){
            int xd=x+arr[i][0];
            int yd=y+arr[i][1];
            if(xd>=0&&yd>=0&&xd<grid.size()&&yd<grid[0].size()&&grid[xd][yd]==1){
                dfs(xd,yd,grid);
            }
        }
    }
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int ans=0;
        for(int i=0;i<grid.size();i++){
            for(int j=0;j<grid[0].size();j++){
                if(grid[i][j]==1){
                    z=0;
                    dfs(i,j,grid);
                    ans=max(ans,z);
                }
            }
        }
        return ans;
    }
};