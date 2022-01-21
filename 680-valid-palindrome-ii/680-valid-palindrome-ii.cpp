class Solution {
public:
    bool func(string &s,int i,int j,int c){
        if(i>j){
            return true;
        }
        if(s[i]!=s[j]){
            if(c==1){
                return false;
            }
            bool l=func(s,i+1,j,c+1);
            if(l){
                return true;
            }
            bool r=func(s,i,j-1,c+1);
            return l||r;
        }
        return func(s,i+1,j-1,c);
        
    }
    bool validPalindrome(string s) {
        return func(s,0,s.size()-1,0);
    }
};