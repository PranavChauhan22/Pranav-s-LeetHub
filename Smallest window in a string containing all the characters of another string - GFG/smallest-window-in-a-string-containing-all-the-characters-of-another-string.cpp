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
        vector<int> arr(26,0);
        int cnt=0;
        for(int i=0;i<p.size();i++){
            if(arr[p[i]-'a']==0){
                cnt++;
                
            }
            arr[p[i]-'a']++;
        }
        
        int len=INT_MAX;
        int start=-1;
        int i=0,j=0;
        while(j<s.size()){
            arr[s[j]-'a']--;
            if(arr[s[j]-'a']==0){
                cnt--;
            }
            if(cnt==0){
                while(cnt==0){
                    if(j-i+1<len){
                        len=j-i+1;
                        start=i;
                    }
                    arr[s[i]-'a']++;
                    if(arr[s[i]-'a']>0){
                        cnt++;
                    }
                    i++;
                }
            }
            j++;
        }
        if(len!=INT_MAX){
            return s.substr(start,len);
        }
        return "-1";
        
        
        
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