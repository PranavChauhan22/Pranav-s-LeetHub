// { Driver Code Starts
// Initial template for C++
#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
// User function template for c++
class Solution {
  public:
    int findMaxLen(string s) {
        stack<int> st;
        for(int i=0;i<s.size();i++){
            if(s[i]=='('){
                st.push(-2);
            }else{
                int w=0;
                while(st.size()>0&&st.top()!=-2&&st.top()!=-1){
                    w+=st.top();
                    st.pop();
                }
                if(st.size()>0&&st.top()==-1){
                    st.push(w);
                    st.push(-1);
                }
                else if(st.size()>0&&st.top()==-2){
                     st.pop();
                    st.push(w+2);
                   
                }else{
                    st.push(w);
                    st.push(-1);
                }
            }
        }
        int ans=0;
        int z=0;
        while(st.size()>0){
            int r=st.top();
            st.pop();
            if(r==-1||r==-2){
                z=0;
            }else{
                z+=r;
            }
            ans=max(ans,z);
        }
        return ans;
    }
};


// { Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        string S;
        cin >> S; 
        Solution ob;
        cout << ob.findMaxLen(S) << endl;
    }
    return 0;
}
  // } Driver Code Ends