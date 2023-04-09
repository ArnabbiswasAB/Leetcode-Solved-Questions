//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
    public:
    //Function to find unit area of the largest region of 1s.
    int findMaxArea(vector<vector<int>>& grid) {
        // Code here
        
        int m = grid.size(), n = grid[0].size();
        queue<pair<int,int>>q;
        int max_area = 0;
        
        int dx[8] = {1,-1,0,0,-1,1,-1,1};
        int dy[8] = {0,0,1,-1,-1,-1,1,1};
        
        
        for(int i=0; i<m; i++){
            for(int j=0; j<n; j++){
                
                if(grid[i][j] == 0)
                continue;
                int count = 0;
                
                q.push({i,j});
                while(!q.empty()){
                    count++;
                    auto it = q.front();
                    q.pop();
                    grid[it.first][it.second] = 0;
                    
                    for(int k=0; k<8; k++){
                        int x = dx[k] + it.first;
                        int y = dy[k] + it.second;
                        
                        if(x<0 || y<0 || x>=m || y>=n || grid[x][y] == 0)
                        continue;
                        
                        q.push({x,y});
                        grid[x][y] = 0;
                    }
                }
                
                max_area = max(max_area, count);
            }
        }
        
        return max_area;
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
		int ans = obj.findMaxArea(grid);
		cout << ans << "\n";
	}
	return 0;
}
// } Driver Code Ends