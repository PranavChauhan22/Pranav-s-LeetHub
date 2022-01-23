class Solution {
public:
    int maximum69Number (int num) {
        string w=to_string(num);
        for(int i=0;i<w.size();i++){
            if(w[i]=='6'){
                w[i]='9';break;
            }
        }
        return stoi(w);
    }
};