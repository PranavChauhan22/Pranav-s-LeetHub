// { Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
// User function Template for C++

class Solution {
  public:
  
    struct Pair{
      int i;
      int j;
      int wgt;
      Pair(int _i,int _j,int _wgt){
          i=_i;
          j=_j;
          wgt=_wgt;
      }
    };
    
    
    struct comp{
      bool operator()(Pair &a, Pair &b){
          return a.wgt>b.wgt;
      }  
    };
    
    int shortestDistance(int N, int M, vector<vector<int>> A, int X, int Y) {
        
        if(A[X][Y]==0){
            return -1;
        }
        if(A[0][0]==0){
            return -1;
        }
        
        priority_queue<Pair,vector<Pair>,comp> pq;
        pq.push(Pair(0,0,0));
        vector<vector<bool>> vis(N,vector<bool>(M,false));
        
        while(pq.size()>0){
            Pair src=pq.top();pq.pop();
            if(src.i==X&&src.j==Y){
                return src.wgt;
            }
            
            if(vis[src.i][src.j]){
                continue;
            }
            
            vis[src.i][src.j]=true;
            
            int arr[4][2]={{1,0},{-1,0},{0,1},{0,-1}};
            
            for(int i=0;i<4;i++){
                int x=src.i+arr[i][0];
                int y=src.j+arr[i][1];
                if(x>=0&&y>=0&&x<A.size()&&y<A[0].size()&&A[x][y]==1&&!vis[x][y]){
                    pq.push(Pair(x,y,src.wgt+1));
                }
            }
        }
        return -1;
    }
};

// { Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int N, M, x, y;
        cin >> N >> M;
        vector<vector<int>> v(N, vector<int>(M));
        for (int i = 0; i < N; i++)
            for (int j = 0; j < M; j++) cin >> v[i][j];
        cin >> x >> y;
        Solution ob;
        cout << ob.shortestDistance(N, M, v, x, y) << "\n";
    }
}  // } Driver Code Ends