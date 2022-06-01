// { Driver Code Starts
//Initial template for C++

#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
//User function template for C++

// A : given string to search
// B : vector of available strings

class Solution
{
public:
    bool solve(string A,unordered_map<string,bool>&mp,int idx){
        if(idx==A.size()){
            return true;
        }
        string ans="";
        for(int i=idx;i<A.size();i++){
            ans+=A[i];
            if(mp.find(ans)!=mp.end()){
                if(solve(A,mp,i+1)){return true;}
            }
        }
        return false;
    }
    int wordBreak(string A, vector<string> &B) {
        unordered_map<string,bool> mp;
        for(auto it:B){
            mp[it]=true;
        }
       return solve(A,mp,0);
    }
};

// { Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        vector<string> dict;
        for(int i=0;i<n;i++){
            string S;
            cin>>S;
            dict.push_back(S);
        }
        string line;
        cin>>line;
        Solution ob;
        cout<<ob.wordBreak(line, dict)<<"\n";
    }
}
  // } Driver Code Ends