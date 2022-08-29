class Solution {
public:
    /*
    int numIslands(vector<vector<char>>& grid) {
        
        int area=0;
        int m = grid.size();
        int n = grid[0].size();
        int dx[4] = {1,-1,0,0};
        int dy[4] = {0,0,-1,1};
        queue<pair<int,int>>q;
        
        for(int i=0; i<m; i++){
            for(int j=0; j<n; j++){
                
                if(grid[i][j] == '0')
                    continue;
                
                if(grid[i][j] == '1'){
                    
                    area++;
                    q.push({i,j});
                    while(!q.empty()){
                        
                        auto p = q.front();
                        q.pop();
                        int x = p.first , y = p.second;
                        
                        for(int i=0; i<4; i++){
                            
                            int newX = x + dx[i];
                            int newY = y + dy[i];
                            
                            if(newX<0 || newY<0 || newX>=m || newY>=n || grid[newX][newY] == '0')
                                continue;
                            
                            if(grid[newX][newY] == '1')
                            {
                                grid[newX][newY] = '0';
                                q.push({newX,newY});
                            }
                        }
                    }
                }
                
            }
        }
        return area;
    }
    */
    
    void dfs(int i, int j, int m,int n, vector<vector<char>>& grid){
        
        if(i<0 || j<0 || i>=m || j>=n || grid[i][j] == '0')
            return;
        
        grid[i][j] = '0';
        dfs(i+1,j,m,n,grid);
        dfs(i-1,j,m,n,grid);
        dfs(i,j+1,m,n,grid);
        dfs(i,j-1,m,n,grid);
        
    }
    
     int numIslands(vector<vector<char>>& grid) {
         
         
         int m = grid.size() , n = grid[0].size();
         int answer=0;
         
         for(int i=0; i<m; i++){
             for(int j=0; j<n; j++){
                 
                 if(grid[i][j] == '1'){
                     answer++;
                     dfs(i,j,m,n, grid);
                 }
                 
             }
         }
          return answer;
           
     }
};