//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
    // Function to find the number of islands.
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
                
                
                q.push({i,j});
                islands++;
                
                while(!q.empty()){
                    
                    int row = q.front().first;
                    int col = q.front().second;
                    grid[row][col] = '0';
                    q.pop();
                    
                    for(int ind=0; ind<8; ind++){
                        int x = row + dx[ind];
                        int y = col + dy[ind];
                        
                        if(x>=0 && y>=0 && x<m && y<n && grid[x][y] == '1'){
                            grid[x][y] = '0';
                            q.push({x,y});
                        }
                    }
                }
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