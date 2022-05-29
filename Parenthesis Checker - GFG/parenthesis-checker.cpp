// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


 // } Driver Code Ends


class Solution
{
    public:
    //Function to check if brackets are balanced or not.
    bool ispar(string x)
    {
        stack<char> st;
        for(int i=0;i<x.size();i++){
            if(x[i]=='{'||x[i]=='('||x[i]=='['){
                st.push(x[i]);
            }else{
                if(st.size()>0){
                    if(x[i]==')'&&st.top()=='('){
                        st.pop();
                    }
                    else if(x[i]==']'&&st.top()=='['){
                        st.pop();
                    }
                    else if(x[i]=='}'&&st.top()=='{'){
                        st.pop();
                    }
                    else{
                        return false;
                    }
                }else{
                    return false;
                }
            }
        }
        return (st.size()==0);
    }

};

// { Driver Code Starts.

int main()
{
   int t;
   string a;
   cin>>t;
   while(t--)
   {
       cin>>a;
       Solution obj;
       if(obj.ispar(a))
        cout<<"balanced"<<endl;
       else
        cout<<"not balanced"<<endl;
   }
}  // } Driver Code Ends