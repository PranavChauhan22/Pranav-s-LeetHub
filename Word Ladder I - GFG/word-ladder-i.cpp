// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution {
public:

    struct Pair{
      int i;
      int wgt;
      Pair(int _i,int _wgt){
          i=_i;
          wgt=_wgt;
      }
    };
    
    struct comp{
      bool operator()(Pair &a, Pair &b){
          return a.wgt>b.wgt;
      }  
    };


    bool check(string a, string b){
        int cnt=0;
        for(int i=0;i<a.size();i++){
            if(a[i]!=b[i]){
                cnt++;
            }
        }
        
        return (cnt<=1);
    }    
        
    int wordLadderLength(string startWord, string targetWord, vector<string>& wordList) {
        
        wordList.push_back(startWord);
        vector<int> g[wordList.size()];
        for(int i=0;i<wordList.size()-1;i++)
        {
            for(int j=i+1;j<wordList.size();j++){
                if(check(wordList[i],wordList[j])){
                    g[i].push_back(j);
                    g[j].push_back(i);
                }
            }
        }
        
        priority_queue<Pair,vector<Pair>,comp>pq;
        for(int i=0;i<wordList.size();i++){
            if(startWord==wordList[i]){
                pq.push(Pair(i,1));
            }
        }
        
        vector<bool> vis(wordList.size(),false);
        
        while(pq.size()>0){
            Pair src=pq.top();pq.pop();
            if(wordList[src.i]==targetWord){
                return src.wgt;
            }
            if(vis[src.i]){
                continue;
            }
            
            vis[src.i]=true;
            
            for(auto it:g[src.i]){
                if(!vis[it]){
                    pq.push(Pair(it,src.wgt+1));
                }
            }
        }
        
        return 0;
        
        
        
        
    }
};

// { Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n;
		cin >> n;
		vector<string>wordList(n);
		for(int i = 0; i < n; i++)cin >> wordList[i];
		string startWord, targetWord;
		cin >> startWord >> targetWord;
		Solution obj;
		int ans = obj.wordLadderLength(startWord, targetWord, wordList);
		cout << ans << "\n";
	}
	return 0;
}  // } Driver Code Ends