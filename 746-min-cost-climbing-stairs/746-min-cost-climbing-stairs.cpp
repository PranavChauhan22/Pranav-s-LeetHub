class Solution {
public:
    int minCostClimbingStairs(vector<int>& cost) {
        vector<int> ans(cost.size(),0);
        for(int i=cost.size()-1;i>=0;i--){
            if(i!=cost.size()-1&&i!=cost.size()-2){
 ans[i]=min(ans[i+1],ans[i+2]);
            }
            ans[i]+=cost[i];
            
        }
        return min(ans[0],ans[1]);
    }
};