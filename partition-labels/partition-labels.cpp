class Solution {
public:
    vector<int> partitionLabels(string s) {
        vector<int> v1(26,INT_MIN);
        for(int i=0;i<s.size();i++){
           v1[s[i]-'a']=max(v1[s[i]-'a'],i);
        }
        int idx=0;
        int k=0;
        vector<int> ans;
        for(int i=0;i<s.size();i++){
            idx=max(idx,v1[s[i]-'a']);
            if(idx==i){
                ans.push_back(i-k+1);
                k=i+1;
                idx=i+1;
            }
        }
        if(s.size()-k!=0){
            ans.push_back(s.size()-1-k);
        }
        
        return ans;
    }
};