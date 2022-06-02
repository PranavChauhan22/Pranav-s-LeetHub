// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
class Solution
{
    public:
    //Function to find the smallest window in the string s consisting
    //of all the characters of string p.
    string smallestWindow (string s, string p)
    {
        vector<int> mp(256,0);
        int cnt=0;
        for(int i=0;i<p.size();i++){
            if(mp[p[i]]==0){
                cnt++;
            }
            mp[p[i]]++;
        }
        int ans=INT_MAX,start=0;
        int i=0,j=0;
        while(j<s.size()){
            mp[s[j]]--;
            if(mp[s[j]]==0){
                cnt--;
            }
            if(cnt==0){
            while(cnt==0){
                if(j-i+1<ans){
                    ans=min(ans,j-i+1);
                    start=i;
                }
                mp[s[i]]++;
                if(mp[s[i]]>0){
                    cnt++;
                }
                i++;
            }
            }
            j++;
        }
        if(ans==INT_MAX){
            return "-1";
        }
        return s.substr(start,ans);
    }
};

// { Driver Code Starts.
int main()
 {
    int t;
    cin>>t;
    while(t--)
    {
        string s;
        cin>>s;
        string pat;
        cin>>pat;
        Solution obj;
        cout<<obj.smallestWindow(s, pat)<<endl;
        
    }
	return 0;
}  // } Driver Code Ends