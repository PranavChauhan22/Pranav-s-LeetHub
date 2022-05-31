class Solution {
public:
    vector<int> sortByBits(vector<int>& arr) {
        vector<pair<int,int>>ans;
        for(int i=0;i<arr.size();i++){
            int r=arr[i];
            int bits=0;
            while(r>0){ // procedure to get no of 1 bits in number
                bits++;
                r-=(r&(-r));
            }
            ans.push_back(make_pair(bits,arr[i]));
        }
        sort(ans.begin(),ans.end()); //sorting based on 
        vector<int> v;
        for(auto it:ans){
            v.push_back(it.second);
        }
        return v;
        
        
    }
};