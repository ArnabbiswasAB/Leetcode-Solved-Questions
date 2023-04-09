//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
    // Function to find the number of islands.
    void dfs(vector<vector<char>>& grid, int i,int j,int m, int n){
        
        if(i<0 || j<0 || i>=m || j>=n || grid[i][j] == '0')
        return;
        
        grid[i][j] = '0';
        
        dfs(grid, i+1, j, m, n);
        dfs(grid, i-1, j, m, n);
        dfs(grid, i, j+1, m, n);
        dfs(grid, i, j-1, m, n);
         dfs(grid, i+1, j+1, m, n);
          dfs(grid, i+1, j-1, m, n);
           dfs(grid, i-1, j+1, m, n);
            dfs(grid, i-1, j-1, m, n);
    }
    
    
    int numIslands(vector<vector<char>>& grid) {
        // Code here
        
        int islands = 0, m = grid.size(), n = grid[0].size();
        queue<pair<int,int>>q;
        int dx[8] = {1,-1,0,0,-1,1,1,-1};
        int dy[8] = {0,0,1,-1,-1,1,-1,1};
        
        for(int i=0; i<m; i++){
            for(int j=0; j<n; j++){
                
                if(grid[i][j] == '0')
                continue;
                
                
                islands++;
                dfs(grid, i,j, m,n);
            }
        }
        
        
        return islands;
    }
};

//{ Driver Code Starts.
int main() {
    int tc;
    cin >> tc;
    while (tc--) {
        int n, m;
        cin >> n >> m;
        vector<vector<char>> grid(n, vector<char>(m, '#'));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                cin >> grid[i][j];
            }
        }
        Solution obj;
        int ans = obj.numIslands(grid);
        cout << ans << '\n';
    }
    return 0;
}
// } Driver Code Ends