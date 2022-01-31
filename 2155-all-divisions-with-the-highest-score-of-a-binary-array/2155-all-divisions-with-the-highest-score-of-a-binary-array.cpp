class Solution {
public:
    vector<int> maxScoreIndices(vector<int>& nums) {
        vector<int> pre_zero(nums.size());

        vector<int> post_one(nums.size());

        for(int i=0;i<nums.size();i++){
            if(i==0){
                if(nums[i]==0){
                    pre_zero[0]=1;
                }
            }else{
                if(nums[i]==0){
                    pre_zero[i]+=pre_zero[i-1]+1;
     
                }else{
                    pre_zero[i]+=pre_zero[i-1];
                }
            }
        }
        for(int i=nums.size()-1;i>=0;i--){
            if(i==nums.size()-1){
                if(nums[i]==1){
                    post_one[nums.size()-1]=1;
                }
            }else{
                if(nums[i]==1){
                    post_one[i]+=post_one[i+1]+1;

                }else{
                    post_one[i]+=post_one[i+1];
           
                }
            }
        }
        int ans=INT_MIN;
        unordered_map<int,int> mp;
        for(int i=1;i<nums.size();i++){
            mp[i]=pre_zero[i-1]+post_one[i];
            ans=max(ans,pre_zero[i-1]+post_one[i]);
        }
        ans=max(ans,max(pre_zero[nums.size()-1],post_one[0]));
        mp[0]=post_one[0];
        mp[nums.size()]=pre_zero[nums.size()-1];
        vector<int> v;
        for(auto it:mp){
            if(it.second==ans){
                v.push_back(it.first);
            }
        }
        return v;
        
    }
};