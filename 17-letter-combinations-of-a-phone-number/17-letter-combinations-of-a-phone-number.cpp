class Solution {
public:
    vector<string> letterCombinations(string digits) {
        unordered_map<char,vector<char>>mp;
         mp['2'].push_back('a');
         mp['2'].push_back('b');
         mp['2'].push_back('c');
         mp['3'].push_back('d');
         mp['3'].push_back('e');
         mp['3'].push_back('f');
         mp['4'].push_back('g');
         mp['4'].push_back('h');
         mp['4'].push_back('i');
         mp['5'].push_back('j');
         mp['5'].push_back('k');
         mp['5'].push_back('l');
         mp['6'].push_back('m');
         mp['6'].push_back('n');
         mp['6'].push_back('o');
         mp['7'].push_back('p');
         mp['7'].push_back('q');
         mp['7'].push_back('r');
         mp['7'].push_back('s');
         mp['8'].push_back('t');
         mp['8'].push_back('u');
         mp['8'].push_back('v');
         mp['9'].push_back('w');
         mp['9'].push_back('x');
         mp['9'].push_back('y');
         mp['9'].push_back('z');
        vector<vector<string>>ans;
        vector<string> w;
        w.push_back("");
        ans.push_back(w);
        for(int i=0;i<digits.size();i++){
            vector<string> v=ans[ans.size()-1];
            vector<string> req;
            for(int j=0;j<v.size();j++){
                for(auto it:mp[digits[i]]){
                req.push_back(v[j]+it);
                }
            }
            ans.push_back(req);
        }
        if(ans.size()==1){
            vector<string>rw;
            
            return rw;
        }
        return ans[ans.size()-1];
        
        
    }
};