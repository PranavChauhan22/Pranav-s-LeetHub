// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
class Solution{
  public:
    // arr[] : the input array
    // N : size of the array arr[]
    
    //Function to return length of longest subsequence of consecutive integers.
    int findLongestConseqSubseq(int arr[], int N)
    {
      map<int,int> mp;
      for(int i=0;i<N;i++){
          mp[arr[i]]++;
      }
      vector<int> v;
      for(auto it:mp){
          v.push_back(it.first);
      }
      vector<int> dp(v.size(),1);
      for(int i=1;i<v.size();i++){
          if(v[i]==v[i-1]+1){
              dp[i]+=dp[i-1];
          }
      }
      
      return *max_element(dp.begin(),dp.end());
    }
};

// { Driver Code Starts.
 
// Driver program
int main()
{
 int  t,n,i,a[100001];
 cin>>t;
 while(t--)
 {
  cin>>n;
  for(i=0;i<n;i++)
  cin>>a[i];
  Solution obj;
  cout<<obj.findLongestConseqSubseq(a, n)<<endl;
 }
      
    return 0;
}  // } Driver Code Ends