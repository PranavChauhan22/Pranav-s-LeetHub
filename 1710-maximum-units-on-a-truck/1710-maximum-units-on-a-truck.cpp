class Solution {
public:
    bool static comp(vector<int> a,vector<int> b){
        return a[1]>b[1];
    }
    int maximumUnits(vector<vector<int>>& boxTypes, int truckSize) {
        int ans=0;
        sort(boxTypes.begin(),boxTypes.end(),comp);
        for(int i=0;i<boxTypes.size();i++){
            int k=boxTypes[i][0];
            while(k>0&&truckSize>=1){
                k--;
                ans+=boxTypes[i][1];
                truckSize--;
            }
            if(truckSize==0){
                break;
            }
        }
        return ans;
    }
};