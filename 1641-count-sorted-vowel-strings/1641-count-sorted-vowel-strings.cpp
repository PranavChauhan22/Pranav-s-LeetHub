class Solution {
public:
    int countVowelStrings(int n) {
        vector<int> v1(5,1);
        for(int j=2;j<=n;j++)
        {
            for(int i=v1.size()-2;i>=0;i--){
                v1[i]+=v1[i+1];
            }
         
        }
        
        return accumulate(v1.begin(),v1.end(),0);
    }
};
