class Solution {
public:
    string frequencySort(string s) {
        map<char,int> mp;
        for(int i=0;i<s.size();i++){
            mp[s[i]]++;
        }
        string ans="";
        vector<pair<int,char>>v1;
        for(auto it:mp){
            v1.push_back(make_pair(it.second,it.first));
            
        }
        sort(v1.begin(),v1.end(),greater<pair<int,char>>());
        for(int i=0;i<v1.size();i++){
            string stu(v1[i].first,v1[i].second);
            ans+=stu;
        }
        return ans;
    }
};