class Solution {
public:
    vector<int> restoreArray(vector<vector<int>>& adjacentPairs) {
        unordered_map<int,vector<int>>mp;
        for(auto it:adjacentPairs){
            mp[it[0]].push_back(it[1]);
            mp[it[1]].push_back(it[0]);
        }
        int i=-1;
        for(auto it:mp){
            if(it.second.size()==1){
                i=it.first;
                break;
            }
        }
        vector<int> ans;
        
        
        int n=adjacentPairs.size();
        unordered_map<int,bool> vis;
        
        while(ans.size()<(n+1)){
            vis[i]=true;
            ans.push_back(i);
            for(auto it:mp[i]){
                if(vis.find(it)==vis.end()){
                    i=it;
                    break;
                }
            }
        }
        return ans;
    }
};