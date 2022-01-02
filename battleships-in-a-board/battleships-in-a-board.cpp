class Solution {
public:
    int ans=0;
    void dfs(int x,int y,vector<vector<char>>&board){
        if(x<0||y<0||x>=board.size()||y>=board[0].size()||board[x][y]=='.')
        {
            return;
        }
        board[x][y]='.';
        dfs(x+1,y,board);
        dfs(x,y+1,board);
        dfs(x-1,y,board);
        dfs(x,y-1,board);
    }
    int countBattleships(vector<vector<char>>& board) {
        // queue<pair<int,int>>q;
        for(int i=0;i<board.size();i++){
            for(int j=0;j<board[0].size();j++){
                if(board[i][j]=='X'){
                    dfs(i,j,board);
                    ans++;
                }
                
            }
            
        }
        return ans;
        // int arr[4][2]={{-1,0},{0,1},{1,0},{0,-1}};
        // while(q.size()>0){
        //     pair<int,int> src=q.top();q.pop();
        //     if(board[src.first][src.second]=='.'){
        //         continue;
        //     }
        //     board[src.first][src.second]='X';
        //     for(int i=0;i<4;i++){
        //         int x=src.first+arr[i][0];
        //         int y=src.second+arr[i][1];
        //         if(x>=0&&y>=0&&x<board.size()&&y<board[0].size()&&board[x][y]=='X'){
        //             q.push(make_pair(x,y));
        //         }
        //     }
        // }
    }
};