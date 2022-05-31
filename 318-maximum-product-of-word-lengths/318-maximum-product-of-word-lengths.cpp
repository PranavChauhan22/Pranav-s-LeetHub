class Solution {
public:
    int max(int a,int b){
        if(a>b){
            return a;
        }
        return b;
    }
    int maxProduct(vector<string>& words) {
        unordered_map<int,bool> mp;
        vector<int> bits(words.size());
        for(int i=0;i<words.size();i++){
            int w=0;
            for(int j=0;j<words[i].size();j++){
                if(mp.find(words[i][j])==mp.end()){
                    w+=(1<<(words[i][j]-'a'));
                    mp[words[i][j]]=true;
                }
              
            }
            mp.clear();
            bits[i]=w;
        }
        int ans=0;
        for(int i=0;i<words.size()-1;i++){
            for(int j=i+1;j<words.size();j++){
                if((bits[i]&bits[j])==0){

                    ans=max(ans,words[i].size()*words[j].size());
                }
            }
        }
        
        return ans;
    }
};