//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
  
  void dfs(vector<vector<int>>& grid, int i, int j){
   
   if(i<0 || j<0 || i>=grid.size() || j>=grid[0].size() || grid[i][j] == 0)
   return;

   grid[i][j] = 0;
   dfs(grid,i+1,j);
   dfs(grid,i-1,j);
   dfs(grid,i,j-1);
   dfs(grid,i,j+1);

   return;
}
  
  int count(vector<vector<int>>& grid){
        int n = grid.size();
        int m = grid[0].size();
        int ans = 0;
        
        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                if(grid[i][j] == 1)
                    ans++;
            }
        }
        
        return ans;
    }


    int numberOfEnclaves(vector<vector<int>> &grid) {
        // Code here
        
        int m = grid.size();
        int n = grid[0].size();
        
        for(int i=0; i<m; i++){
            int j=0; 
            if(grid[i][j] == 1){
                dfs(grid,i,j);
            }
            
            j=n-1;
            if(grid[i][j] == 1)
            {
                dfs(grid,i,j);
            }
        }
        
        
        for(int j=0; j<n; j++){
            int i=0;
            if(grid[i][j] == 1){
                dfs(grid,i,j);
            }
            
            i=m-1;
            if(grid[i][j] == 1){
                dfs(grid,i,j);
            }
        }
        
        return count(grid);
    }
};


//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, m;
        cin >> n >> m;
        vector<vector<int>> grid(n, vector<int>(m));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                cin >> grid[i][j];
            }
        }
        Solution obj;
        cout << obj.numberOfEnclaves(grid) << endl;
    }
}
// } Driver Code Ends