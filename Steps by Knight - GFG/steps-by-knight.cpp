// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution 
{
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
        bool operator()(Pair &a,Pair &b){
            return a.wgt>b.wgt;
        }  
    };
    
    //Function to find out minimum steps Knight needs to reach target position.
	int minStepToReachTarget(vector<int>&KnightPos,vector<int>&TargetPos,int N)
	{
	    int arr[8][2]={{2,1},{-2,1},{-2,-1},{2,-1},{1,2},{1,-2},{-1,2},{-1,-2}};
	    vector<vector<bool>>vis(N+1,vector<bool>(N+1,false));
	    priority_queue<Pair,vector<Pair>,comp>pq;
	    pq.push(Pair(KnightPos[0],KnightPos[1],0));
	    while(pq.size()>0){
	        Pair src=pq.top();pq.pop();
	        if(src.i==TargetPos[0]&&src.j==TargetPos[1]){
	            return src.wgt;
	        }
	        if(vis[src.i][src.j]){
	            continue;
	        }
	        vis[src.i][src.j]=true;
	        for(int i=0;i<8;i++){
	            int x=src.i+arr[i][0];
	            int y=src.j+arr[i][1];
	            if(x>=0&&y>=0&&x<=N&&y<=N&&!vis[x][y]){
	                pq.push(Pair(x,y,src.wgt+1));
	            }
	        }
	    }
	    return -1;
	}
};

// { Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		vector<int>KnightPos(2);
		vector<int>TargetPos(2);
		int N;
		cin >> N;
		cin >> KnightPos[0] >> KnightPos[1];
		cin >> TargetPos[0] >> TargetPos[1];
		Solution obj;
		int ans = obj.minStepToReachTarget(KnightPos, TargetPos, N);
		cout << ans <<"\n";
	}
	return 0;
}  // } Driver Code Ends