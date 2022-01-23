class Solution {
public:
    int numBusesToDestination(vector<vector<int>>& routes, int source, int target) {
        unordered_map<int,bool> busstop;
              unordered_map<int,vector<int>>mp;
        unordered_map<int,bool> busstoppoint;
        for(int i=0;i<routes.size();i++){
            for(int j=0;j<routes[i].size();j++){
                busstoppoint[routes[i][j]]=false;
                mp[routes[i][j]].push_back(i);
            }
            busstop[i]=false;
        }
        queue<int>q;q.push(source);
        busstoppoint[source]=true;
        int lvl=0;
        while(q.size()>0){
            int size=q.size();
            while(size--){
                int src=q.front();q.pop();
                if(src==target){
                    return lvl;
                }
             
                vector<int>v=mp[src];
                for(int i=0;i<v.size();i++){
                    if(busstop[v[i]]==false){
                        vector<int> v1=routes[v[i]];
                        
                        for(int j=0;j<v1.size();j++){
                            if(busstoppoint[v1[j]]==false){
                                q.push(v1[j]);
                                busstoppoint[v1[j]]=true;
                            }
                        }
                        
                    }
                    busstop[v[i]]=true;
                }
            }
      
            lvl++;
        }
        return -1;
  
        
    }
};