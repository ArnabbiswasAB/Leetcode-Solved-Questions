//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution 
{
    public:
    //Function to find minimum time required to rot all oranges. 
    int orangesRotting(vector<vector<int>>& grid) {
        // Code here
        
        int m = grid.size(), n = grid[0].size();
        queue<pair<int,int>>q;
        int count = 0, times = 0, size = 0;
        
        
        for(int i=0; i<m; i++){
            for(int j=0; j<n; j++){
                
                if(grid[i][j] == 2)
                {
                    count++;
                    q.push({i,j});
                }else if(grid[i][j] == 1){
                    count++;
                }
            }
        }
        
        int dx[4] = {1,-1,0,0};
        int dy[4] = {0,0,1,-1};
        
        while(!q.empty()){
            
            int k = q.size();
            size += k;
            
            
            for(int i=0; i<k; i++){
                
                auto it = q.front();
                q.pop();
                
                for(int k=0; k<4; k++){
                    
                    int x = it.first + dx[k];
                    int y = it.second + dy[k];
                    
                    if(x<0 || y<0 || x>=m || y>=n || grid[x][y] != 1)
                    continue;
                    
                    grid[x][y] = 2;
                    q.push({x,y});
                }
            }
            
            if(!q.empty())
            times++;
        }
        
        if(count == size)
        return times;
        
        return -1;
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
		int ans = obj.orangesRotting(grid);
		cout << ans << "\n";
	}
	return 0;
}
// } Driver Code Ends