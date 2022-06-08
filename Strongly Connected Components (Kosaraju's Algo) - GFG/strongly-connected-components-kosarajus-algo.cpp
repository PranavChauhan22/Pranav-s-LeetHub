// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends


class Solution
{
	public:
	//Function to find number of strongly connected components in the graph.
	void dfs(int i,vector<int> adj[],stack<int>&st,vector<bool>&vis){
	    vis[i]=true;
	    for(auto it:adj[i]){
	        if(!vis[it]){
	            dfs(it,adj,st,vis);
	        }
	    }
	    st.push(i);
	}
	void newDfs(int i,vector<bool>&vis,vector<int> graph[]){
	    vis[i]=true;
	    for(auto it:graph[i]){
	        if(!vis[it]){
	            newDfs(it,vis,graph);
	        }
	    }
	}
    int kosaraju(int V, vector<int> adj[])
    {
        stack<int> st;
        vector<bool> vis(V,false);
        for(int i=0;i<V;i++){
            if(!vis[i]){
            dfs(i,adj,st,vis);
            }
        }
        vector<bool> newVis(V,false);
        vector<int> graph[V];
        for(int i=0;i<V;i++){
            for(auto it:adj[i]){
                graph[it].push_back(i);
            }
        }
        int ans=0;
        while(st.size()>0){
            int i=st.top();st.pop();
            if(!newVis[i]){
                newDfs(i,newVis,graph);
                ans++;
            }
        }
        return ans;
    }
};

// { Driver Code Starts.


int main()
{
    
    int t;
    cin >> t;
    while(t--)
    {
    	int V, E;
    	cin >> V >> E;

    	vector<int> adj[V];

    	for(int i = 0; i < E; i++)
    	{
    		int u, v;
    		cin >> u >> v;
    		adj[u].push_back(v);
    	}

    	Solution obj;
    	cout << obj.kosaraju(V, adj) << "\n";
    }

    return 0;
}

  // } Driver Code Ends