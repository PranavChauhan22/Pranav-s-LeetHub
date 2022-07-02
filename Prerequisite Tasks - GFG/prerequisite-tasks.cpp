// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution {
public:

    bool cycle(int i,vector<bool> &vis,vector<bool> &newVis,vector<int> g[]){
        vis[i]=true;
        newVis[i]=true;
        for(auto it:g[i]){
            if(!vis[it]){
                if(cycle(it,vis,newVis,g)){
                    return true;
                }
            }else if(newVis[it]){
                return true;
            }
        }
        newVis[i]=false;
        return false;
    }

	bool isPossible(int N, vector<pair<int, int> >& prerequisites) {
	    vector<int> g[N];
	    for(auto it:prerequisites){
	        g[it.second].push_back(it.first);
	    }
	    vector<bool> vis(N,false);
	    vector<bool> newVis(N,false);
	    for(int i=0;i<N;i++){
	        if(cycle(i,vis,newVis,g)){
	            return false;
	        }
	    }
	    return true;
	}
};

// { Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
    	int N, P;
        vector<pair<int, int> > prerequisites;
        cin >> N;
        cin >> P;
        for (int i = 0; i < P; ++i) {
            int x, y;
            cin >> x >> y;
            prerequisites.push_back(make_pair(x, y));
        }
        // string s;
        // cin>>s;
        Solution ob;
        if (ob.isPossible(N, prerequisites))
            cout << "Yes";
        else
            cout << "No";
        cout << endl;
	}
	return 0;
}  // } Driver Code Ends