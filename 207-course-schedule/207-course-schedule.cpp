class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        vector<int> g[numCourses];
        vector<int> indeg(numCourses,0);
        for(auto it:prerequisites){
            g[it[0]].push_back(it[1]);
            indeg[it[1]]++;
        }
        
        queue<int> q;
        for(int i=0;i<numCourses;i++){
            if(indeg[i]==0){
                q.push(i);
            }
        }
        while(q.size()>0){
            int s=q.size();
            while(s--){
                int src=q.front();q.pop();
                for(auto it:g[src]){
                    indeg[it]--;
                    if(indeg[it]==0){
                        q.push(it);
                    }
                }
            }
        }
        
        for(int i=0;i<numCourses;i++){
            if(indeg[i]!=0){
                return false;
            }
        }
        return true;
        
        
        
    }
};