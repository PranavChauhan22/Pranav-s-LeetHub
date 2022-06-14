// { Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
// User function Template for C++

class Solution{
public:
    bool solve(int N,int arr[],int s,int i){
        
        if(s==0){
            return true;
        }
        if(i==N){
            return false;
        }
        if(s>=arr[i]){
        int l=solve(N,arr,s-arr[i],i+1);
        if(l){
            return true;
        }
        }
        if(solve(N,arr,s,i+1)){
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
        return solve(N,arr,sum/2,0);
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