// { Driver Code Starts
//Initial template for C++ 
 
#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends

//User function template for C++

class Solution{
  public:		
	int lps(string s) {
	    vector<int> lps(s.size(),0);
	    int i=1,len=0;
	    while(i<s.size()){
	        if(s[i]==s[len]){
	            len++;
	            lps[i]=len;
	            i++;
	        }else{
	            if(len>0){
	                len=lps[len-1];
	            }else{
	                lps[i]=0;
	                i++;
	            }
	        }
	    }
	    
	    
	    return lps[s.size()-1];
	}
};

// { Driver Code Starts.

int main() 
{
   

   	ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    cout.tie(NULL);
   
   	int t;
   	cin >> t;
   	while(t--)
   	{
   		string str;
   		cin >> str;

   		Solution ob;

   		cout << ob.lps(str) << "\n";
   	}

    return 0;
}
  // } Driver Code Ends