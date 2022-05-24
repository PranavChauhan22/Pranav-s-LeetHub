// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution
{
    
	public:
	    void solve(set<string> &ans,vector<char> v,string S,int idx){
	        if(idx==S.size()){
                string str="";
                for(auto it:v){
                    str+=it;
                }
                ans.insert(str);
                return;
	        }
	        for(int i=0;i<v.size();i++){
	            if(v[i]=='.'){
	                v[i]=S[idx];
	                solve(ans,v,S,idx+1);
	                v[i]='.';
	            }
	        }
	        
	    }
		vector<string>find_permutation(string S)
		{
		    vector<string> ans;
		    set<string> w;
		    vector<char> v(S.size(),'.');
		    solve(w,v,S,0);
		    for(auto it:w){
		        ans.push_back(it);
		    }
		    return ans;
		}
};



// { Driver Code Starts.
int main(){
    int t;
    cin >> t;
    while(t--)
    {
	    string S;
	    cin >> S;
	    Solution ob;
	    vector<string> ans = ob.find_permutation(S);
	    for(auto i: ans)
	    {
	    	cout<<i<<" ";
	    }
	    cout<<"\n";
    }
	return 0;
}
  // } Driver Code Ends