// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends


class Solution
{
    public:
    //Function to find length of longest increasing subsequence.
    int longestSubsequence(int n, int a[])
    {
        vector<int> dp(n,1);
        for(int i=1;i<n;i++){
            int w=INT_MIN;
            for(int j=i-1;j>=0;j--){
                if(a[j]<a[i]){
                    w=max(w,dp[j]);
                }
            }
            if(w!=INT_MIN){
                dp[i]=w+1;
            }
        }
        return *max_element(dp.begin(),dp.end());
    }
};

// { Driver Code Starts.
int main()
{
    //taking total testcases
    int t,n;
    cin>>t;
    while(t--)
    {
        //taking size of array
        cin>>n;
        int a[n];
        
        //inserting elements to the array
        for(int i=0;i<n;i++)
            cin>>a[i];
        Solution ob;
        //calling method longestSubsequence()
        cout << ob.longestSubsequence(n, a) << endl;
    }
}
  // } Driver Code Ends