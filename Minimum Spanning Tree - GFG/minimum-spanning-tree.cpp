// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends


class Solution
{
	public:
	struct Pair{
	    int x;
	    int y;
	    int wgt;
	    Pair(int _wgt,int _y,int _x){
	        wgt=_wgt;
	        y=_y;
	        x=_x;
	    }
	};
bool static comp(Pair a,Pair b){
    return a.wgt<b.wgt;
}
	//Function to find sum of weights of edges of the Minimum Spanning Tree.
	int find(int x, vector<int>&par){
	    if(par[x]==x){
	        return x;
	    }
	    par[x]=find(par[x],par);
	    return par[x];
	}
	bool unionI(int x,int y,vector<int>&par,vector<int> &rank){
	    int lx=find(x,par);
	    int ly=find(y,par);
	    if(lx!=ly){
	        if(rank[lx]>rank[ly]){
	            par[ly]=lx;
	        }else if(rank[ly]>rank[lx]){
	            par[lx]=ly;
	        }else{
	            par[lx]=ly;
	            rank[ly]++;
	        }
	        return true;
	    }
	        return false;
	    
	}
    int spanningTree(int V, vector<vector<int>> adj[])
    {
        
        vector<int> par(V);
        vector<int> rank(V,0);
        for(int i=0;i<V;i++){
            par[i]=i;
        }
        int ans=0;
        vector<Pair> v;
        
        for(int i=0;i<V;i++){
            for(auto it:adj[i]){
                v.push_back(Pair(it[1],it[0],i));
            }
        }
        sort(v.begin(),v.end(),comp);
        for(auto it:v){
            if(unionI(it.x,it.y,par,rank)){
                ans+=it.wgt;
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