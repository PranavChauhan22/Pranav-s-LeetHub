class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int cap=0,def=0,sidx=0;
        for(int i=0;i<gas.size();i++){
            cap+=gas[i]-cost[i];
            if(cap<0){
                def+=cap;
                sidx=i+1;
                cap=0;
            }
        }
        if(cap+def>=0){
            return sidx;
        }
        return -1;
    }
};