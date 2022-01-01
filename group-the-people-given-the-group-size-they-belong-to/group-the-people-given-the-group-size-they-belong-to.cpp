class Solution {
public:
    vector<vector<int>> groupThePeople(vector<int>& groupSizes) {
        unordered_map<int,vector<int>>mp;
        for(int i=0;i<groupSizes.size();i++){
            mp[groupSizes[i]].push_back(i);
        }
        vector<vector<int>>ans;
        for(auto it:mp){
            vector<int> v1=it.second;
            int s=it.first;
            vector<int> a;
            for(int i=0;i<v1.size();i++){
                a.push_back(v1[i]);
                if(a.size()==s){
                    ans.push_back(a);
                    a.clear();
                }
            }
        }
        return ans;
    }
};