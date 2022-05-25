// { Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
// User function Template for C++

class Solution{
public:
    bool solve(int N,int arr[],int idx,int sum){
        if(sum==0){
            return true;
        }
        if(idx==N){
            return false;
        }
        if(arr[idx]<=sum){
            if(solve(N,arr,idx+1,sum-arr[idx])){return true;}   
        }
        if(solve(N,arr,idx+1,sum)){return true;}  
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
       return solve(N,arr,0,sum/2);
        
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