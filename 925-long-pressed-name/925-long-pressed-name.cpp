class Solution {
public:
    bool isLongPressedName(string name, string typed) {
        vector<pair<char,int>>v;
        v.push_back(make_pair(name[0],1));
        for(int i=1;i<name.size();i++){
           if(name[i]==name[i-1]){
               v[v.size()-1].second++;
           }else{
               v.push_back(make_pair(name[i],1));
           }
        }
        vector<pair<char,int>>v1;
        v1.push_back(make_pair(typed[0],1));
        for(int i=1;i<typed.size();i++){
           if(typed[i]==typed[i-1]){
               v1[v1.size()-1].second++;
           }else{
               v1.push_back(make_pair(typed[i],1));
           }
        }
        
        if(v.size()!=v1.size()){
            return false;
        }
        for(int i=0;i<v.size();i++){
            if(v[i].first!=v1[i].first){
                return false;
            }
            if(v[i].second>v1[i].second){
                return false;
            }
        }
        return true;
    }
};