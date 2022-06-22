// { Driver Code Starts
#include<bits/stdc++.h>
#include<stdlib.h>
#include<iostream>
using namespace std;

 // } Driver Code Ends
/* You are required to complete the function below
*  arr[]: input array
*  n: size of array
*/
class Solution{
  public:
    //Function to find triplets with zero sum.
    bool findTriplets(int arr[], int n)
    { 
        
        unordered_map<int,int> mp;
        for(int i=0;i<n;i++){
            mp[arr[i]]=i;
        }
        for(int i=0;i<n-1;i++){
            for(int j=i+1;j<n;j++){
                int w=-(arr[i]+arr[j]);
                if(mp.find(w)!=mp.end()&&mp[w]!=i&&mp[w]!=j){
                    return true;
                }
            }
        }
        return false;
    }
};

// { Driver Code Starts.
int main()
{
    int t;
	cin>>t;
	while(t--){
    	int n;
    	cin>>n;
    	int arr[n]={0};
    	for(int i=0;i<n;i++)
    		cin>>arr[i];
    	Solution obj;
        if(obj.findTriplets(arr, n))
            cout<<"1"<<endl;
        else 
            cout<<"0"<<endl;
	}
    return 0;
}  // } Driver Code Ends