class Solution {
public:
    vector<int> minOperations(string boxes) {
        vector<int> ans(boxes.size());
        vector<int> presum(boxes.size());
        vector<int> postsum(boxes.size());
        vector<int> precnt(boxes.size());
        vector<int> postcnt(boxes.size());
        for(int i=0;i<boxes.size();i++){
                ans[i]=i*(boxes[i]-'0')+(i!=0?ans[i-1]:0);
            
        }
        for(int i=1;i<ans.size();i++){
            if(boxes[i]=='1'){
                presum[i]=ans[i]-i;
            }else{
                presum[i]=ans[i-1];
            }
        }
        for(int i=boxes.size()-1;i>=0;i--){
                ans[i]=i*(boxes[i]-'0')+(i!=boxes.size()-1?ans[i+1]:0);
            
        }
        for(int i=ans.size()-2;i>=0;i--){
        if(boxes[i]=='1'){
                postsum[i]=ans[i]-i;
            }else{
                postsum[i]=ans[i+1];
            }
        }
        for(int i=0;i<precnt.size();i++){
            ans[i]=(boxes[i]-'0')+(i!=0?ans[i-1]:0);
        }
        for(int i=0;i<precnt.size();i++){
            precnt[i]=(i==0?0:ans[i-1]);
        }
        for(int i=postcnt.size()-1;i>=0;i--){
            ans[i]=(boxes[i]-'0')+(i!=postcnt.size()-1?ans[i+1]:0);
        }
        for(int i=0;i<postcnt.size();i++){
            postcnt[i]=(i==postcnt.size()-1?0:ans[i+1]);
        }
        for(int i=0;i<ans.size();i++){
            ans[i]=abs(presum[i]-precnt[i]*i)+abs(postsum[i]-postcnt[i]*i);
        }
        return ans;
    }
};
// 0 1 2 3 4 5
// 0 0 1 0 1 1 
// 0 0 2 0 4 5
// 0 0 0 2 2 6
// 0 0 2 2 6 11
// 0 0 0 1 1 2
// 11 11 9 9 5 0
// // 11 11 9 9 5 4