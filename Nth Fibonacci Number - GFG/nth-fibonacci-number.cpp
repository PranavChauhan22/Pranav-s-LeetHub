// { Driver Code Starts
// Initial Template for C++
#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
// User function Template for C++
class Solution {
  public:
    long long int nthFibonacci(long long int n){
            int mod=1e9+7;
            vector<long long int>dp(n+1);
            dp[1]=1;
            dp[2]=1;
            for(int i=3;i<=n;i++){
                dp[i]=(dp[i-1]+dp[i-2])%mod;
            }
            return dp[n]%mod;
    }
};

// { Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        long long int n;
        cin >> n;
        Solution ob;
        cout << ob.nthFibonacci(n) << endl;
    }
    return 0;
}
  // } Driver Code Ends