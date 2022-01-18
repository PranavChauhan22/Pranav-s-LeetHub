class Solution {
public:
    int longestSubarray(vector<int>& nums) {
        vector<pair<int,int>>v1;
        int o=0;
        int ans=0;
        for(int i=0;i<nums.size();i++){
            if(nums[i]==0){
                if(o>0){
                      v1.push_back(make_pair(1,o));
                    o=0;
                }
                v1.push_back(make_pair(0,1));
            }else{
                o++;
            }
        }

        if(o>0){
             v1.push_back(make_pair(1,o));
        }
                
        for(int i=1;i<v1.size()-1;i++){
            if(v1[i].first==1){
                ans=max(ans,v1[i].second-1);
                if(v1[i-1].first==0||v1[i+1].first==0){
                    ans=max(ans,v1[i].second);
                }
            }else{
                if(v1[i-1].first==1&&v1[i+1].first==1){
                    ans=max(ans,v1[i-1].second+v1[i+1].second);
                }else if(v1[i-1].first==1){
                    ans=max(ans,v1[i-1].second);
                }else if(v1[i+1].first==1){
                    ans=max(ans,v1[i+1].second);
                }
            }
        }
            if(v1[0].first==1){
                ans=max(ans,v1[0].second-1);
            }
            if(v1[v1.size()-1].first==1){
                        ans=max(ans,v1[v1.size()-1].second-1);
            }
    
        return ans;
    }
};