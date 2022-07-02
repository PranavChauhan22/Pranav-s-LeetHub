// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends


class Solution 
{
    public:
    //Function to find a Mother Vertex in the Graph.
    
    void dfs(stack<int> &st,vector<int> g[],vector<bool> &vis,int src){
        vis[src]=true;
        for(auto it:g[src]){
            if(!vis[it]){
                dfs(st,g,vis,it);
            }
        }
        st.push(src);
    }
    
    void newDfs(vector<int> g[],vector<bool> &vis,int src){
        vis[src]=true;
        for(auto it:g[src]){
            if(!vis[it]){
                newDfs(g,vis,it);
            }
        }
    }
    
    
	int findMotherVertex(int V, vector<int>adj[])
	{
        stack<int> st;
        vector<bool> vis(V,false);
        dfs(st,adj,vis,0);
        vector<bool> newVis(V,false);
        newDfs(adj,newVis,st.top());
        if(count(newVis.begin(),newVis.end(),true)==V){
         return st.top();   
        }
        
        return -1;
	}

};

// { Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int V, E;
		cin >> V >> E;
		vector<int>adj[V];
		for(int i = 0; i < E; i++){
			int u, v;
			cin >> u >> v;
			adj[u].push_back(v);
		}
		Solution obj;
		int ans = obj.findMotherVertex(V, adj);
		cout << ans <<"\n";
	}
	return 0;
}  // } Driver Code Ends