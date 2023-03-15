//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends

class Solution
{
    public:
    //Function to find whether a path exists from the source to destination.
    bool is_Possible(vector<vector<int>>& grid) 
    {
        //code here
        int m = grid.size(), n = grid[0].size();
        queue<pair<int,int>>q;
        
        for(int i=0; i<m; i++){
            for(int j=0; j<n; j++){
                
                if(grid[i][j] == 1){
                    q.push({i,j});
                    break;
                }
                
            }
            
            if(!q.empty())
            break;
        }
        
        
        if(q.empty())
        return false;
        
        int dx[4] = {1,-1,0,0};
        int dy[4] = {0,0,1,-1};
        
        while(!q.empty()){
            
            auto it = q.front();
            q.pop();
            grid[it.first][it.second] = 0;
            
            for(int k=0; k<4; k++){
                int x = dx[k] + it.first;
                int y = dy[k] + it.second;
                
                if(x<0 || y<0 || x>=m || y>=n || grid[x][y] == 0)
                continue;
                
                if(grid[x][y] == 2){
                return true;
               }
            
               grid[x][y] = 0;
               q.push({x,y});
            }
        }
        
        
        return false;
    }
};

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n;
		cin >> n;
		vector<vector<int>>grid(n, vector<int>(n, -1));
		for(int i = 0; i < n; i++){
			for(int j = 0; j < n; j++){
				cin >> grid[i][j];
			}
		}
		Solution obj;
		bool ans = obj.is_Possible(grid);
		cout << ((ans) ? "1\n" : "0\n");
	}
	return 0;
}
// } Driver Code Ends