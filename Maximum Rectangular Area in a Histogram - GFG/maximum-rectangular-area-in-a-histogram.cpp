// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
class Solution
{
    public:
    //Function to find largest rectangular area possible in a given histogram.
    long long getMaxArea(long long arr[], int n)
    {
        stack<long long> st;
        vector<long long> nser(n,n);
        st.push(n-1);
        for(int i=n-2;i>=0;i--){
            while(st.size()>0&&arr[st.top()]>=arr[i]){
                st.pop();
            }
            if(st.size()!=0){
                nser[i]=st.top();
            }
            st.push(i);
        }
        while(st.size()>0){
            st.pop();
        }
        vector<long long> nsel(n,-1);
        st.push(0);
        for(int i=1;i<n;i++){
            while(st.size()>0&&arr[st.top()]>=arr[i]){
                st.pop();
            }
            if(st.size()!=0){
                nsel[i]=st.top();
            }
            st.push(i);
        }
        long long ans=0;
        for(int i=0;i<n;i++){
            ans=max(ans,(nser[i]-nsel[i]-1)*arr[i]);
        }
        return ans;
        
    }
};


// { Driver Code Starts.

int main()
 {
    long long t;

    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        
        long long arr[n];
        for(int i=0;i<n;i++)
            cin>>arr[i];
        Solution ob;
        cout<<ob.getMaxArea(arr, n)<<endl;
    
    }
	return 0;
}
  // } Driver Code Ends