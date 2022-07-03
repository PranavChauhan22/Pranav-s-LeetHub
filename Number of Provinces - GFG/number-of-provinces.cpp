// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
//User function Template for C++

class Solution {
  public:
  
  void dfs(int src,vector<int> g[],vector<bool> &vis){
      vis[src]=true;
      for(auto it:g[src]){
          if(!vis[it]){
              dfs(it,g,vis);
          }
      }
      
  }
  
    int numProvinces(vector<vector<int>> adj, int V) {
        vector<int> g[V];
        for(int i=0;i<V;i++){
            for(int j=0;j<V;j++){
                if(adj[i][j]==1){
                    g[i].push_back(j);
                }
            }
        }
        
        vector<bool> vis(V,false);
        int ans=0;
        for(int i=0;i<V;i++){
            if(!vis[i]){
                dfs(i,g,vis);
                ans++;
            }
        }
        return ans;
    }
};

// { Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int V,x;
        cin>>V;
        
        vector<vector<int>> adj;
        
        for(int i=0; i<V; i++)
        {
            vector<int> temp;
            for(int j=0; j<V; j++)
            {
                cin>>x;
                temp.push_back(x);
            }
            adj.push_back(temp);
        }
        

        Solution ob;
        cout << ob.numProvinces(adj,V) << endl;
    }
    return 0;
}  // } Driver Code Ends