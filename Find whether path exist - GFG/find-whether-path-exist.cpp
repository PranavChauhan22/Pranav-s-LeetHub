// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends

class Solution
{
    public:
    //Function to find whether a path exists from the source to destination.
    
    bool solve(vector<vector<bool>> &vis,vector<vector<int>> &grid,int i,int j){
        if(i<0||j<0||i>=grid.size()||j>=grid[0].size()||grid[i][j]==0||vis[i][j]){
            return false;
        }
        if(grid[i][j]==2){
            return true;
        }
        vis[i][j]=true;
        return (solve(vis,grid,i+1,j)||solve(vis,grid,i-1,j)||solve(vis,grid,i,j+1)||solve(vis,grid,i,j-1));
    }
    
    
    bool is_Possible(vector<vector<int>>& grid) 
    {
        vector<vector<bool>>vis(grid.size(),vector<bool>(grid[0].size(),false));
        for(int i=0;i<grid.size();i++){
            for(int j=0;j<grid[0].size();j++){
                if(grid[i][j]==1){
                    if(solve(vis,grid,i,j)){
                        return true;
                    }else{
                        return false;
                    }
                }
            }
        }
        return false;
    }
};

// { Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n;
		cin >> n;
		vector<vector<int>>grid(n, vector<int>(n, -1));
		for(int i = 0; i < n; i++){
			for(int j = 0; j < n; j++){
				cin >> grid[i][j];
			}
		}
		Solution obj;
		bool ans = obj.is_Possible(grid);
		cout << ((ans) ? "1\n" : "0\n");
	}
	return 0;
}  // } Driver Code Ends