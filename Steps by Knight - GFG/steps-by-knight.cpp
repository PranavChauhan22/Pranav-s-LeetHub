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
        int l;
        Pair(int _x,int _y, int _l){
            x=_x;
            y=_y;
            l=_l;
        }
    };
    struct comp{
        bool operator()(Pair &a,Pair &b){
            return a.l>b.l;
        }
    };
    //Function to find out minimum steps Knight needs to reach target position.
	int minStepToReachTarget(vector<int>&KnightPos,vector<int>&TargetPos,int N)
	{
        int arr[8][2]={{1,2},{1,-2},{-1,2},{-1,-2},{2,1},{2,-1},{-2,-1},{-2,1}};
        priority_queue<Pair,vector<Pair>,comp>pq;
        pq.push(Pair(KnightPos[0],KnightPos[1],0));
        vector<vector<bool>>vis(N+1,vector<bool>(N+1,false));
        while(pq.size()>0){
            Pair src=pq.top();pq.pop();
            if(src.x==TargetPos[0]&&src.y==TargetPos[1]){
                return src.l;
            }
            if(vis[src.x][src.y]){
                continue;
            }
            vis[src.x][src.y]=true;
            for(int i=0;i<8;i++){
                int xd=src.x+arr[i][0];
                int yd=src.y+arr[i][1];
                if(xd>=1&&yd>=1&&xd<=N&&yd<=N&&!vis[xd][yd]){
                    pq.push(Pair(xd,yd,src.l+1));
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