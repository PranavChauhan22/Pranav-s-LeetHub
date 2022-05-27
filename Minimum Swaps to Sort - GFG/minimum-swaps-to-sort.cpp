// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends


class Solution 
{
    public:
    //Function to find the minimum number of swaps required to sort the array. 
	int minSwaps(vector<int>&nums)
	{
	    vector<int> v=nums;
	    sort(v.begin(),v.end());
	    unordered_map<int,int> mp;
	    for(int i=0;i<nums.size();i++){
	        mp[nums[i]]=i;
	    }
	    int ans=0;
	    for(int i=0;i<v.size();i++)
	    {
	        if(nums[i]!=v[i]){
	            int req_idx=mp[v[i]];
	            mp[nums[i]]=req_idx;
	            mp[v[i]]=i;
	            int t=nums[i];
	            nums[i]=nums[req_idx];
	            nums[req_idx]=t;
	            ans++;
	        }
	    }
	    return ans;
	}
};

// { Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n;
		cin >> n;
		vector<int>nums(n);
		for(int i = 0; i < n; i++)
			cin >> nums[i];
		Solution obj;
		int ans = obj.minSwaps(nums);
		cout << ans <<"\n";
	}
	return 0;
}  // } Driver Code Ends