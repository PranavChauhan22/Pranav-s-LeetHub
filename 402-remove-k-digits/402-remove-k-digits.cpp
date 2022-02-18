class Solution {
public:
    string removeKdigits(string num, int k) {
        if(k==num.size()){
            return "0";
        }
        stack<char> st;
        for(int i=0;i<num.size();i++){
            while(st.size()>0&&st.top()>num[i]&&k){
                st.pop();
                k--;
            }
            st.push(num[i]);
        }
        while(k--){
            st.pop();
        }
        string ans="";
        while(st.size()>0)
        {
            ans+=st.top();
            st.pop();
        }
        reverse(ans.begin(),ans.end());
        int i=0;
        while(ans[i]=='0'){
            i++;
        }
        if(i==ans.size())
        {
            return "0";
        }
        return ans.substr(i,ans.size());
    }
};