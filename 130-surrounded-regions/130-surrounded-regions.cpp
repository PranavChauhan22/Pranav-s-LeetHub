class Solution {
public:
    void dfs(int x,int y,vector<vector<char>>&board,vector<vector<char>>&ans){
        int arr[4][2]={{1,0},{-1,0},{0,1},{0,-1}};
        ans[x][y]='O';
        board[x][y]='X';
        for(int i=0;i<4;i++){
            int xd=x+arr[i][0];
            int yd=y+arr[i][1];
            if(xd>=0&&yd>=0&&xd<board.size()&&yd<board[0].size()&&board[xd][yd]=='O'){
                dfs(xd,yd,board,ans);
            }
        }
    }
    void solve(vector<vector<char>>& board) {
        vector<vector<char>>ans(board.size(),vector<char>(board[0].size(),'X'));
        for(int i=0;i<board.size();i++){
            if(board[i][0]=='O'){
            dfs(i,0,board,ans);
            }
        }
        for(int i=0;i<board.size();i++){
            if(board[i][board[0].size()-1]=='O'){
            dfs(i,board[0].size()-1,board,ans);
            }
        }
        for(int j=0;j<board[0].size();j++){
            if(board[0][j]=='O'){
                dfs(0,j,board,ans);
            }
        }
        for(int j=0;j<board[0].size();j++){
            if(board[board.size()-1][j]=='O'){
                dfs(board.size()-1,j,board,ans);
            }
        }
        board=ans;
    }
};