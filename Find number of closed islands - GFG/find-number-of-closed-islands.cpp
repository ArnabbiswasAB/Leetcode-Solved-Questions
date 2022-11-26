//{ Driver Code Starts
//Initial Template for C++

#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function Template for C++

class Solution {
    public:
    
    int bfs(vector<vector<int>> &mat){
     
      int cnt = 0;
      queue<pair<int,int>>q;
      int m = mat.size();
      int n = mat[0].size();
      
      for(int i=0; i<m; i++){
          for(int j=0; j<n; j++){
              
              if(mat[i][j] == 1){
                  
                  q.push({i,j});
                  cnt++;
                  mat[i][j] = 0;
                  
                  while(!q.empty()){
                      
                      auto it = q.front();
                      q.pop();
                      
                     
                      
                      int dx[4] = {1,-1,0,0};
                      int dy[4] = {0,0,1,-1};
                      
                      for(int i=0; i<4; i++){
                          int x = it.first + dx[i];
                          int y = it.second + dy[i];
                          
                          if(x<0 || y<0 || x>=m || y>=n || mat[x][y]!=1)
                          continue;
                          
                          mat[x][y] = 0;
                          q.push({x,y});
                      }
                  }
              }
          }
      }
      return cnt;
    }
    
    void dfs(vector<vector<int>>& mat,int i, int j, int N, int M){
        
        if(i<0 || j<0 || i>=N || j>=M || mat[i][j] == 0)
        return;
        
        mat[i][j] = 0;
        dfs(mat, i+1, j, N, M);
        dfs(mat, i-1, j, N, M);
        dfs(mat, i,j+1, N,M);
        dfs(mat,i, j-1, N, M);
        
        return;
    }
    
    int closedIslands(vector<vector<int>>& mat, int N, int M) {
        // Code here
        
        for(int i=0; i<N; i++){
            
            if(mat[i][0] == 1)
               dfs(mat, i, 0, N, M);
               
            if(mat[i][M-1] == 1)
            dfs(mat, i, M-1, N, M);
        }
        
        
        for(int i=0; i<M; i++){
            
            if(mat[0][i] == 1)
               dfs(mat, 0, i, N, M);
               
            if(mat[N-1][i] == 1) 
               dfs(mat, N-1, i, N, M);
        }
        
        return bfs(mat);
    }
};

//{ Driver Code Starts.
int main() {
	int t;
	cin>>t;
	while(t--)
	{
        int N, M;
        cin >> N >> M;
        vector<vector<int>>matrix(N, vector<int>(M, 0));
        for(int i=0; i<N; i++)
            for(int j=0; j<M; j++)
                cin >> matrix[i][j];
                
        Solution obj;
        int ans = obj.closedIslands(matrix, N, M);
        cout << ans << "\n";
    }
	
	return 0;
	
}


// } Driver Code Ends