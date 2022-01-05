class Solution {
public:
    bool canVisitAllRooms(vector<vector<int>>& rooms) {
        vector<int> graph[rooms.size()];
        for(int i=0;i<rooms.size();i++){
            for(int j=0;j<rooms[i].size();j++){
                graph[i].push_back(rooms[i][j]);
            }
        }
        int n=rooms.size();
        queue<pair<int,int>> q;
        vector<bool> vis(rooms.size(),false);
        q.push(make_pair(0,1));
        while(q.size()>0){
            pair<int,int> src=q.front();q.pop();
            if(vis[src.first]){
                continue;
            }
            vis[src.first]=true;
            for(auto it:graph[src.first]){
                if(vis[it]==false){
                    q.push(make_pair(it,src.second+1));
                }
            }
        }
        int ans=0;
        for(auto it:vis){
            if(it){
                ans++;
            }
        }
        return (ans==n);
    }
};