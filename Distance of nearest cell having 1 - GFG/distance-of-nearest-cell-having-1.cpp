//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution 
{
    public:
    //Function to find distance of nearest 1 in the grid for each cell.
	vector<vector<int>>nearest(vector<vector<int>>grid)
	{
	    // Code here
	    int m = grid.size(), n = grid[0].size();
	    
	    queue<pair<int,int>>q;
	    vector<vector<int>> vis(m, vector<int>(n, 1e9));
	    
	    for(int i=0; i<m; i++){
	        for(int j=0; j<n; j++){
	            if(grid[i][j] == 1){
	                vis[i][j] = 0;
	                q.push({i,j});
	            }
	        }
	    }
	    
	    int dx[4] = {1,-1,0,0};
	    int dy[4] = {0,0,1,-1};
	    
	    while(!q.empty()){
	        
	        auto it = q.front();
	        q.pop();
	        
	        for(int i=0; i<4; i++){
	            int x = dx[i] + it.first;
	            int y = dy[i] + it.second;
	            
	            if(x<0 || y<0 || x>=m || y>=n || vis[x][y] != 1e9)
	            continue;
	            
	            if(1 + vis[it.first][it.second] < vis[x][y]){
	                vis[x][y] = 1 + vis[it.first][it.second];
	                q.push({x,y});
	            }
	        }
	    }
	    
	    return vis;
	}
};

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n, m;
		cin >> n >> m;
		vector<vector<int>>grid(n, vector<int>(m, -1));
		for(int i = 0; i < n; i++){
			for(int j = 0; j < m; j++){
				cin >> grid[i][j];
			}
		}
		Solution obj;
		vector<vector<int>> ans = obj.nearest(grid);
		for(auto i: ans){
			for(auto j: i){
				cout << j << " ";
			}
			cout << "\n";
		}
	}
	return 0;
}
// } Driver Code Ends