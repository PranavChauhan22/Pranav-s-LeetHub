class Solution {
public:
    int minSwaps(string s) {
        stack<char> st;
        for(int i=0;i<s.size();i++){
            if(s[i]=='['){
                st.push(s[i]);
            }else{
                if(st.size()>0&&st.top()=='['){
                    st.pop();
                }else{
                    st.push(']');
                }
            }
        }
        int w=st.size()/2;
        if(w%2!=0){
            w++;
        }
        return w/2;
    }
};
