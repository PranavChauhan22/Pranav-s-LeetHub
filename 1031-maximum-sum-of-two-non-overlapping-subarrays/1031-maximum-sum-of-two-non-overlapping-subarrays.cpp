class Solution {
public:
    int func(vector<int> nums,int firstLen,int secondLen)
    {
        vector<int> fsum(nums.size()),ssum(nums.size());
        fsum[0]=nums[0];
        for(int i=1;i<firstLen;i++){
            fsum[i]=fsum[i-1]+nums[i];
        }
        for(int i=firstLen;i<nums.size();i++){
            fsum[i]=nums[i]+fsum[i-1]-nums[i-firstLen];
        }
        for(int i=firstLen;i<nums.size();i++){
            fsum[i]=max(fsum[i-1],fsum[i]);
        }
        ssum[nums.size()-1]=nums[nums.size()-1];
        for(int i=nums.size()-2;i>=nums.size()-secondLen;i--){
            ssum[i]=ssum[i+1]+nums[i];
        }
        for(int i=nums.size()-1-secondLen;i>=0;i--){
            ssum[i]=ssum[i+1]+nums[i]-nums[i+secondLen];
        }
        for(int i=nums.size()-1-secondLen;i>=0;i--){
            ssum[i]=max(ssum[i+1],ssum[i]);
        }
        int l=firstLen-1;
        int r=nums.size()-secondLen;
        int ans=INT_MIN;
        while(l<r){
            ans=max(ans,fsum[l]+ssum[l+1]);
            l++;
        }
        return ans;
    }
    int maxSumTwoNoOverlap(vector<int>& nums, int firstLen, int secondLen) {
        int a=func(nums,firstLen,secondLen);
        reverse(nums.begin(),nums.end());
        int b=func(nums,firstLen,secondLen);
        return max(a,b);
    }
};