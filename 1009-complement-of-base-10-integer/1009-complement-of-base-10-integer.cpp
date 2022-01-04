class Solution {
public:
    int bitwiseComplement(int n) {
        if(n==0){
            return 1;
        }
        int c=floor(log2(n))+1;
        return ((1<<c)-1)^n;
    }
};