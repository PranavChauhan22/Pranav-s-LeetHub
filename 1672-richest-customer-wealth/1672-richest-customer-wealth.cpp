class Solution {
public:
    int maximumWealth(vector<vector<int>>& accounts) {
        int ans=INT_MIN;
        for(auto it:accounts){
            int s=0;
            for(auto i:it){
                s+=i;
            }
            ans=max(ans,s);
        }
        return ans;
    }
};