// { Driver Code Starts
#include<bits/stdc++.h> 
using namespace std; 

 // } Driver Code Ends
class Solution
{
public:
    vector<int> candyStore(int candies[], int N, int K)
    {
        sort(candies,candies+N);
        int mn=0,mx=0;
        int i=0,j=N-1;
        while(i<=j){
            mn+=candies[i++];
            j-=K;
        }
        i=0,j=N-1;
        while(i<=j){
            mx+=candies[j--];
            i+=K;
        }
        vector<int> v;
        v.push_back(mn);
        v.push_back(mx);
        return v;
    }
};


// { Driver Code Starts.
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int N, K;
        cin >> N >> K;
        int candies[N];

        for (int i = 0; i < N; i++)
        {
            cin >> candies[i];
        }

        Solution ob;
        vector<int> cost = ob.candyStore(candies, N, K);
        cout << cost[0] << " " << cost[1] << endl;
    }
    return 0;
}  // } Driver Code Ends