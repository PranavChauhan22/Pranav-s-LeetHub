class Solution {
public:
    void make_zero(vector<vector<int>>& matrix,int x,int y){
        for(int j=0;j<matrix[0].size();j++){
            matrix[x][j]=0;
        } for(int j=0;j<matrix.size();j++){
            matrix[j][y]=0;
        }
        
        
    }
    void setZeroes(vector<vector<int>>& matrix) {
        queue<pair<int,int>>q;
        for(int i=0;i<matrix.size();i++){
            for(int j=0;j<matrix[0].size();j++){
                if(matrix[i][j]==0){
                    q.push(make_pair(i,j));
                }
            }
        }
        while(q.size()>0){
            pair<int,int> src=q.front();q.pop();
            make_zero(matrix,src.first,src.second);
        }
        
    }
};