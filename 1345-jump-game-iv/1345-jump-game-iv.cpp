class Solution {
public:
    int minJumps(vector<int>& arr) {
        unordered_map<int,vector<int>>mp;
        for(int i=0;i<arr.size();i++){
            mp[arr[i]].push_back(i);
        }
        vector<bool> vis(arr.size(),false);
        queue<int>q;q.push(0);
        int step=0;
        while(q.size()>0){
            int size=q.size();
            while(size--){
                int src=q.front();q.pop();
                if(src==arr.size()-1){
                    return step;
                }
                vis[src]=true;
                vector<int>& next=mp[arr[src]];
                next.push_back(src-1);next.push_back(src+1);
                for(auto it:next){
                    if(it>=0&&it<arr.size()&&!vis[it]){
                        q.push(it);
                    }
                }
                next.clear();
            }
            step++;
        }
        return 0;
    }
};