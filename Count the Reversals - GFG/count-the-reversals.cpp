// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

int countRev (string s);
int main()
{
    int t; cin >> t;
    while (t--)
    {
        string s; cin >> s;
        cout << countRev (s) << '\n';
    }
}

// Contributed By: Pranay Bansal// } Driver Code Ends



int countRev (string s)
{
    if(s.size()%2!=0){
        return -1;
    }
    stack<char> st;
    for(int i=0;i<s.size();i++){
        if(s[i]=='{'){
            st.push(s[i]);
        }else{
            if(st.size()>0&&st.top()!='}'){
                st.pop();
            }else{
            st.push(s[i]);
            }
        }
    }
    int l=0,r=0;
    while(st.size()>0){
        if(st.top()=='{'){
            l++;
        }else{
            r++;
        }
        st.pop();
    }
    return ceil(l/2.0)+ceil(r/2.0);
}
