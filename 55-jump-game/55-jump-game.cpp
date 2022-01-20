class Solution {
public:
    bool canJump(vector<int>& nums) {
        int i=0;
        for(int j=0;j<nums.size();j++){
            if(j>i){
                return false;
            }
            i=max(i,j+nums[j]);
        }
        return true;
    }
};