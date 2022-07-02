// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution 
{
    public:
    //Function to find minimum time required to rot all oranges. 
    int orangesRotting(vector<vector<int>>& grid) {
        queue<pair<int,int>>q;
        int r=0;
        for(int i=0;i<grid.size();i++){
            for(int j=0;j<grid[0].size();j++){
                if(grid[i][j]==2){
                    q.push(make_pair(i,j));
                }else if(grid[i][j]==1){
                    r++;
                }
            }
        }
        int ans=0;
        int arr[4][2]={{1,0},{-1,0},{0,1},{0,-1}};
        while(q.size()>0){
            int s=q.size();
            while(s--)
            {
                pair<int,int> src=q.front();q.pop();
                for(int i=0;i<4;i++){
                    int x=src.first+arr[i][0];
                    int y=src.second+arr[i][1];
                    if(x<0||y<0||x>=grid.size()||y>=grid[0].size()||grid[x][y]!=1){
                        continue;
                    }
                    grid[x][y]=2;
                    q.push(make_pair(x,y));
                    r--;
                }
            }
            ans++;
            
        }
        if(r!=0){
            return -1;
        }
        return ans-1;
    }
};

// { Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n, m;
		cin >> n >> m;
		vector<vector<int>>grid(n, vector<int>(m, -1));
		for(int i = 0; i < n; i++){
			for(int j = 0; j < m; j++){
				cin >> grid[i][j];
			}
		}
		Solution obj;
		int ans = obj.orangesRotting(grid);
		cout << ans << "\n";
	}
	return 0;
}  // } Driver Code Ends