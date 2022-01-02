class Solution {
public:
    int numPairsDivisibleBy60(vector<int>& time) {
        map<int,int> mp;
        long long ans=0;
        for(auto it:time){
            ans+=mp[(600-it)%60];
            mp[it%60]+=1;
        }
        return ans;
    }
};