// { Driver Code Starts
#include <bits/stdc++.h>

using namespace std;

 // } Driver Code Ends
//User function template for C++
class Solution{
public:

	// Function to find maximum product subarray
	long long max(long long a,long long b){
	    if(a>b){
	        return a;
	    }
	    return b;
	}
	long long min(long long a,long long b){
	    if(a>b){
	        return b;
	    }
	    return a;
	}
	long long maxProduct(vector<int> arr, int n) {
	    long long mn=arr[0];
	    long long mx=arr[0];
	    long long ans=arr[0];
	    for(int i=1;i<n;i++){
	        if(arr[i]<0){
	            long long t=mn;
	            mn=mx;
	            mx=t;
	        }
	        mx=max(arr[i],mx*arr[i]);
	        mn=min(arr[i],mn*arr[i]);
	        ans=max(ans,mx);
	    }
	    return ans;
	}
};

// { Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, i;
        cin >> n;
        vector<int> arr(n);
        for (i = 0; i < n; i++) {
            cin >> arr[i];
        }
        Solution ob;
        auto ans = ob.maxProduct(arr, n);
        cout << ans << "\n";
    }
    return 0;
}  // } Driver Code Ends