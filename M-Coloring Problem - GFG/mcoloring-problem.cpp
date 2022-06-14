// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
// Function to determine if graph can be coloured with at most M colours such
// that no two adjacent vertices of graph are coloured with same colour.
bool isSafe(bool graph[101][101],vector<int> &color,int i,int col){
    for(int k=0;k<color.size();k++){
        if(k!=i&&graph[k][i]==1&&color[k]==col){
            return false;
        }
    }
    return true;
}
bool solve(bool graph[101][101],vector<int> color,int i,int m){
    if(i==color.size()){
        return true;
    }
    for(int j=1;j<=m;j++){
        if(isSafe(graph,color,i,j)){
            color[i]=j;
            if(solve(graph,color,i+1,m)){return true;}
            color[i]=0;
        }
    }
    return false;
}

bool graphColoring(bool graph[101][101], int m, int n) {
    vector<int> color(n,0);
    return solve(graph,color,0,m);
    
    
}

// { Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, m, e;
        cin >> n >> m >> e;
        int i;
        bool graph[101][101];
        for (i = 0; i < n; i++) {
            memset(graph[i], 0, sizeof(graph[i]));
        }
        for (i = 0; i < e; i++) {
            int a, b;
            cin >> a >> b;
            graph[a - 1][b - 1] = 1;
            graph[b - 1][a - 1] = 1;
        }
        cout << graphColoring(graph, m, n) << endl;
    }
    return 0;
}
  // } Driver Code Ends