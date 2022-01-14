class Solution {
public:
    bool binsrch(vector<int> v,int val){

        int l=0;
        int r=v.size()-1;
        while(l<=r){
            int mid=(l+r)/2;
            if(v[mid]==val){
                return true;
            }else if(v[mid]>val){
                r=mid-1;
            }else{
                l=mid+1;
            }
        }
    
        return (v[l]==val);
    }
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        for(int i=0;i<matrix.size();i++){
            if((matrix[i][0]<=target)&&(target<=matrix[i][matrix[0].size()-1])){
                return binsrch(matrix[i],target);
            }
        }
        return false;
    }
};