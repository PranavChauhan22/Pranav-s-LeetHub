// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;
// UNASSIGNED is used for empty cells in sudoku grid 
#define UNASSIGNED 0  

// N is used for the size of Sudoku grid.  
// Size will be NxN  
#define N 9  


 // } Driver Code Ends

class Solution 
{
    public:
    //Function to find a solved Sudoku. 

    bool place(int grid[N][N],int r,int c,int w){
        for(int i=0;i<9;i++){
            if(grid[i][c]==w){
                return false;
            }
        }
        for(int i=0;i<9;i++){
            if(grid[r][i]==w){
                return false;
            }
        }
        r=(r/3)*3;
        c=(c/3)*3;
        for(int i=0;i<3;i++){
            for(int j=0;j<3;j++){
                if(grid[r+i][c+j]==w){
                    return false;
                }
            }
        }
        return true;
    }
    bool solve(int grid[N][N],int r,int c){
        if(r==9){
            return true;
        }
        int rd=(c==8?r+1:r);
        int cd=(c==8?0:c+1);
        if(grid[r][c]!=0){
            bool we=solve(grid,rd,cd);
            if(we){
                return true;
            }
        }
        else{
            for(int i=1;i<=9;i++){
            if(place(grid,r,c,i)){
                grid[r][c]=i;
                bool f=solve(grid,rd,cd);
                if(f){
                    return true;
                }
                grid[r][c]=0;
            }
            
            }
        }
        return false;
    }
    bool SolveSudoku(int grid[N][N])  
    { 
      
        bool ans=solve(grid,0,0);
        
        return ans;
    }
    
    //Function to print grids of the Sudoku.
    void printGrid (int grid[N][N]) 
    {
        for(int i=0;i<9;i++){
            for(int j=0;j<9;j++){
                cout<<grid[i][j]<<" ";
            }
            
        }
    }
};

// { Driver Code Starts.

int main() {
	int t;
	cin>>t;
	while(t--)
	{
		int grid[N][N];
		
		for(int i=0;i<9;i++)
		    for(int j=0;j<9;j++)
		        cin>>grid[i][j];
		        
		Solution ob;
		
		if (ob.SolveSudoku(grid) == true)  
            ob.printGrid(grid);  
        else
            cout << "No solution exists";  
        
        cout<<endl;
	}
	
	return 0;
}  // } Driver Code Ends