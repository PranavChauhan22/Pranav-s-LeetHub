// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
class Solution{
  public:
    // arr[]: Input Array
    // N : Size of the Array arr[]
    // Function to count inversions in the array.
    long long mergeSort(long long arr[],long long l, long long m, long long h, long long N){
    long long cnt=0,j=m,i=l;
    vector<long long> temp;
    while(i<=m-1&&j<=h){
        if(arr[i]>arr[j]){
            cnt+=(m-i);
            temp.push_back(arr[j++]);
            
        }else{
            temp.push_back(arr[i++]);
        }
    }
    while(i<=m-1){
         temp.push_back(arr[i++]);
    }
    while(j<=h){
         temp.push_back(arr[j++]);
    }
    for(int i=l;i<=h;i++){
        arr[i]=temp[i-l];
    }
    return cnt;
}
long long merge(long long arr[],long long N,long long l,long long h){
    if(l>=h){
        return 0;
    }
    long long m=(l+h)/2;
    long long inv=merge(arr,N,l,m);
    inv+=merge(arr,N,m+1,h);
    inv+=mergeSort(arr,l,m+1,h,N);
    return inv;
}
long long int inversionCount(long long arr[], long long N)
{
    return merge(arr,N,0,N-1);
}

};

// { Driver Code Starts.

int main() {
    
    long long T;
    cin >> T;
    
    while(T--){
        long long N;
        cin >> N;
        
        long long A[N];
        for(long long i = 0;i<N;i++){
            cin >> A[i];
        }
        Solution obj;
        cout << obj.inversionCount(A,N) << endl;
    }
    
    return 0;
}
  // } Driver Code Ends