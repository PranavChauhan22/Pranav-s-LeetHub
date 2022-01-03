class Solution {
public:
    int findJudge(int n, vector<vector<int>>& trust) {
        unordered_map<int,int> mp1;
        unordered_map<int,int> mp2;
        for(int i=1;i<=n;i++){
            mp1[i]=0;
            mp2[i]=0;
        }
        for(int i=0;i<trust.size();i++){
            mp1[trust[i][1]]++;
        }
        for(int i=0;i<trust.size();i++){
            mp2[trust[i][0]]++;
        }
        for(int i=1;i<=n;i++){
            if(mp1[i]==n-1&&mp2[i]==0){
                return i;
            }
        }
        return -1;
    }
};