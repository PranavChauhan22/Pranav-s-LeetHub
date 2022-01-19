class Solution {
public:
    int minimumDeletions(string s) {
        int a=count(s.begin(),s.end(),'a'),b=0,res=a;
        for(auto it:s){
             b+=(it=='b');
             a-=(it=='a');
            res=min(res,a+b);
        }
        return res;
    }
};