// { Driver Code Starts
#include<bits/stdc++.h>

using namespace std;


 // } Driver Code Ends
class Solution{

    // Function to find the trapped water between the blocks.
    public:
    long long trappingWater(int arr[], int n){
        vector<int> dp1(n);
        vector<int> dp2(n);
        dp1[0]=arr[0];
        dp2[n-1]=arr[n-1];
        for(int i=1;i<n;i++){
            dp1[i]=max(arr[i],dp1[i-1]);
        }
        for(int i=n-2;i>=0;i--){
            dp2[i]=max(arr[i],dp2[i+1]);
        }
        long long ans=0;
        for(int i=0;i<n;i++){
            ans+=min(dp1[i],dp2[i])-arr[i];
        }
        return ans;
    }
};

// { Driver Code Starts.

int main(){
    
    int t;
    //testcases
    cin >> t;
    
    while(t--){
        int n;
        
        //size of array
        cin >> n;
        
        int a[n];
        
        //adding elements to the array
        for(int i =0;i<n;i++){
            cin >> a[i];            
        }
        Solution obj;
        //calling trappingWater() function
        cout << obj.trappingWater(a, n) << endl;
        
    }
    
    return 0;
}  // } Driver Code Ends