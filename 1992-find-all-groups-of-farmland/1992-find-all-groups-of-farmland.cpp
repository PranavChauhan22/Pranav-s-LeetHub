class Solution {
public:
    int xmin=-1,ymin=-1,xmax=-1,ymax=-1;
    void dfs(int x,int y,vector<vector<int>> &land){
        xmin=min(x,xmin);    ymin=min(y,ymin);
        xmax=max(x,xmax);
        land[x][y]=0;
            ymax=max(y,ymax);
        int arr[4][2]={{1,0},{0,1},{-1,0},{0,-1}};
        for(int i=0;i<4;i++){
            int xd=x+arr[i][0];
            int yd=y+arr[i][1];
            if(xd>=0&&yd>=0&&xd<land.size()&&yd<land[0].size()&&land[xd][yd]==1){
                dfs(xd,yd,land);
            }
        }
    }
    vector<vector<int>> findFarmland(vector<vector<int>>& land) {
        vector<vector<int>> ans;
        for(int i=0;i<land.size();i++){
            for(int j=0;j<land[0].size();j++){
                if(land[i][j]==1){
                    xmin=INT_MAX,ymin=INT_MAX,xmax=INT_MIN,ymax=INT_MIN;
                    dfs(i,j,land);
                    vector<int> v;
                    v.push_back(xmin);
                     v.push_back(ymin);
                     v.push_back(xmax);
                     v.push_back(ymax);
                    ans.push_back(v);
                }
            }
        }
        return ans;
    }
};