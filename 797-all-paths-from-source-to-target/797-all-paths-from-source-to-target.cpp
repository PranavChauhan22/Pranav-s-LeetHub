class Solution {
public:
    vector<vector<int>> allPathsSourceTarget(vector<vector<int>>& graph) {
        queue<pair<int,vector<int>>>q;
        vector<int> v1;
        v1.push_back(0);
        q.push(make_pair(0,v1));
        vector<int> g[graph.size()];
        for(int i=0;i<graph.size();i++){
            for(int j=0;j<graph[i].size();j++){
                g[i].push_back(graph[i][j]);
            }
        }
        
        vector<vector<int>>arr;
        while(q.size()>0){
            pair<int,vector<int>>p=q.front();q.pop();
            if(p.first==graph.size()-1){
                arr.push_back(p.second);
            }

       
            
            for(auto it:g[p.first]){
                
                    vector<int> k=p.second;
                    k.push_back(it);
                    q.push(make_pair(it,k));
                
            }
            
        }
        return arr;
    }
};