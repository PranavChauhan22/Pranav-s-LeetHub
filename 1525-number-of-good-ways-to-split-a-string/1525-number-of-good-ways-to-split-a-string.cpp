class Solution {
public:
    int numSplits(string s) {
        unordered_map<char,int> mp1,mp2;
        for(int i=0;i<s.size()-1;i++){
            mp1[s[i]]++;
        }
        mp2[s[s.size()-1]]++;
        int ans=0;
        for(int i=s.size()-2;i>=0;i--){
            // cout<<mp1.size()<<" "<<mp2.size()<<endl;
            if(mp1.size()==mp2.size()){
                ans++;
            }
            mp1[s[i]]--;
            if(mp1[s[i]]==0){
                mp1.erase(s[i]);
            }
            mp2[s[i]]++;
        }
        if(mp1.size()==mp2.size()){
                ans++;
        }
        return ans;        
    }
};