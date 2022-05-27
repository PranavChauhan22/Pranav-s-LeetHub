// { Driver Code Starts
#include<bits/stdc++.h>
 
using namespace std; 


bool findPair(int arr[], int size, int n);

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int l,n;
        cin>>l>>n;
        int arr[l];
        for(int i=0;i<l;i++)
            cin>>arr[i];
        if(findPair(arr, l, n))
            cout<<1<<endl;
        else cout<<"-1"<<endl;
    }
    
  
    return 0;
}// } Driver Code Ends


bool findPair(int arr[], int size, int n){
    unordered_map<int,int> mp;
    for(int i=0;i<size;i++){
        mp[arr[i]]=i;
    }
    for(int i=0;i<size;i++){
        if(mp.find(n+arr[i])!=mp.end()&&mp[n+arr[i]]!=i){
            return true;
        }
    }
    return false;
}