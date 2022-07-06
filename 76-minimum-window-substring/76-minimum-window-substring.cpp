class Solution {
public:
    string minWindow(string s, string t) {
        unordered_map<char,int> mp;
        int count=0;
        for(int i=0;i<t.size();i++){
            if(mp.find(t[i])==mp.end()){
                count++;
            }
            mp[t[i]]++;
        }
        int start=-1;
        int ans=INT_MAX;
        int i=0,j=0;
        while(j<s.size()){
            mp[s[j]]--;
            if(mp[s[j]]==0){
                count--;
            }
            
            if(count==0){
                while(count==0){
                    if(j-i+1<ans){
                        ans=min(ans,j-i+1);
                        start=i;
                    }
                    
                    mp[s[i]]++;
                    if(mp[s[i]]>0){
                        count++;
                    }
                    i++;
                }
            }
            j++;
        }
        if(start==-1){
            return "";   
        }
        
        return s.substr(start,ans);
    }
};