// { Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
// User function Template for C++

class Solution{
public:
    bool solve(int N,int i,int arr[],int sum){
        if(sum==0){
            return true;
        }
        if(i==N){
            return false;
        }
        if(sum>=arr[i]){
        if(solve(N,i+1,arr,sum-arr[i])){
            return true;
        }
        }
        if(solve(N,i+1,arr,sum)){
            return true;
        }
        return false;
    }
    int equalPartition(int N, int arr[])
    {
        int sum=0;
        for(int i=0;i<N;i++){
            sum+=arr[i];
        }
        if(sum%2){
            return 0;
        }
        return solve(N,0,arr,sum/2);
    }
};

// { Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int N;
        cin>>N;
        int arr[N];
        for(int i = 0;i < N;i++)
            cin>>arr[i];
        
        Solution ob;
        if(ob.equalPartition(N, arr))
            cout<<"YES\n";
        else
            cout<<"NO\n";
    }
    return 0;
}  // } Driver Code Ends