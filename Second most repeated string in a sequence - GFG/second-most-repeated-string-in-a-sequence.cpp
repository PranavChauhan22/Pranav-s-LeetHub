// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends

class Solution
{
  public:
    string secFrequent (string arr[], int n)
    {
        int a=INT_MIN,b=INT_MIN;
        string as="",bs="";
        unordered_map<string,int> mp;
        for(int i=0;i<n;i++){
            string it=arr[i];
            mp[it]++;
            if(mp[it]>a){
                a=mp[it];
                as=it;
            }
        }
        for(auto it:mp){
            if(it.second!=a&&it.second>b){
                b=it.second;
                bs=it.first;
            }
        }
        return bs;
    }
};

// { Driver Code Starts.
int main()
{
    int t; cin >> t;
    while (t--)
    {
        int n; cin >> n;
        string arr[n];
        for (int i = 0; i < n; ++i)
            cin >> arr[i];
        Solution ob;
        cout << ob.secFrequent (arr, n) << endl;
    }
}
// Contributed By: Pranay Bansal
  // } Driver Code Ends