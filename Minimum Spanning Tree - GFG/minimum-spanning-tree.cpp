// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends


class Solution
{
	public:
	//Function to find sum of weights of edges of the Minimum Spanning Tree.
	struct Pair{
	    int x;
	    int wgt;
	    Pair(int _x,int _wgt){
	        x=_x;
	        wgt=_wgt;
	    }
	};
	struct comp{
	    bool operator()(struct Pair&a,struct Pair&b){
	        return a.wgt>b.wgt;
	    }
	};
    int spanningTree(int V, vector<vector<int>> adj[])
    {
        int ans=0;
        
        
        priority_queue<Pair,vector<Pair>,comp> pq;
        pq.push(Pair(0,0));
        vector<bool> vis(V,false);
        while(pq.size()>0){
            Pair src=pq.top();pq.pop();
            if(vis[src.x]){
                continue;
            }
            vis[src.x]=true;
            ans+=src.wgt;
            for(auto it:adj[src.x]){
                if(!vis[it[0]]){
                    pq.push(Pair(it[0],it[1]));
                }
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
    while (t--) {
        int V, E;
        cin >> V >> E;
        vector<vector<int>> adj[V];
        int i=0;
        while (i++<E) {
            int u, v, w;
            cin >> u >> v >> w;
            vector<int> t1,t2;
            t1.push_back(v);
            t1.push_back(w);
            adj[u].push_back(t1);
            t2.push_back(u);
            t2.push_back(w);
            adj[v].push_back(t2);
        }
        
        Solution obj;
    	cout << obj.spanningTree(V, adj) << "\n";
    }

    return 0;
}

  // } Driver Code Ends