class Solution {
public:
    bool canReach(string s, int minJump, int maxJump) {
        if(s[s.size()-1]!='0'){
            return false;
        }
        queue<int> q;q.push(0);
        int w=0;
        while(q.size()>0){
            
                int src=q.front();q.pop();
                if(src==s.size()-1){
                    return true;
                }
      
                for(int j=max(int(src+minJump),int(w));j<=min(int(src+maxJump),int(s.size()-1));j++){
                    if(s[j]=='0'){
                        q.push(j);
                    }
                }
            w=min(int(src+maxJump+1),int(s.size()-1));
                
            
        }
        return false;
    }
};