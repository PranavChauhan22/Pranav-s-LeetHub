class Solution {
public:
    vector<string> findOcurrences(string text, string first, string second) {
        string s1="",s2="";
        vector<string> ans;
        string s="";
        text+=' ';
        for(int i=0;i<text.size();i++){
            if(text[i]==' '){
                if(s.size()>0){
                    if(s1.size()==0){
                        s1=s;
                    }else if(s2.size()==0){
                        s2=s;
                    }else{
                        if(s1==first&&s2==second){
                            ans.push_back(s);
                        }
                        s1=s2;
                        s2=s;

                    }
                                            s="";
                }
            }else{
                s+=text[i];
            }
        }return ans;
    }
};