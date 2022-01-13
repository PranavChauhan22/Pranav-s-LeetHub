class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        for(int k=1;k<=matrix.size()-1;k++){
            for(int j=k,i=k;j<matrix[0].size();j++,i++){
                int t=matrix[i][k-1];
                matrix[i][k-1]=matrix[k-1][j];
                matrix[k-1][j]=t;
            }
        }
        
        for(int j=0;j<matrix[0].size()/2;j++){
            for(int i=0;i<matrix.size();i++){
                int t=matrix[i][j];
                matrix[i][j]=matrix[i][matrix.size()-1-j];
                matrix[i][matrix.size()-1-j]=t;
            }
        }
    }
};
