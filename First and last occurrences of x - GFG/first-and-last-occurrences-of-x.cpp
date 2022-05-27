// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
vector<int> find(int arr[], int n , int x )
{
    int l=0,h=n-1;
    while(l<=h){
        int m=(l+h)>>1;
        if(arr[m] >= x){
            h=m-1;
        }else{
            l=m+1;
        }
    }
    vector<int> ans;
    ans.push_back(l);
    l=0,h=n-1;
    while(l<=h){
        int m=(l+h)>>1;
        if(arr[m] <= x){
            l=m+1;
        }else{
            h=m-1;
        }
    }
    ans.push_back(h);
    vector<int> v(2,-1);
    if(arr[ans[0]]!=x){
        return v;
    }
    return ans;
}

// { Driver Code Starts.

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n,x;
        cin>>n>>x;
        int arr[n],i;
        for(i=0;i<n;i++)
        cin>>arr[i];
        vector<int> ans;
        ans=find(arr,n,x);
        cout<<ans[0]<<" "<<ans[1]<<endl;
    }
    return 0;
}


  // } Driver Code Ends