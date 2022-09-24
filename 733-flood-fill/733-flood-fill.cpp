class Solution {
public:
    void dfs(int i,int j,int m,int n,vector<vector<int>>& image, int old, int color){
        
        if(i<0 || j<0 || i>=m || j>=n || image[i][j] != old || image[i][j] == color){
            return;
        }
        
        image[i][j] = color;
        
        dfs(i+1,j,m,n,image,old,color);
        dfs(i,j+1,m,n,image,old,color);
        dfs(i-1,j,m,n,image,old,color);
        dfs(i,j-1,m,n,image,old,color);
        
    }
             
             
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
     
        int m = image.size();
        int n = image[0].size();
        
        int old = image[sr][sc];
       // dfs(sr, sc, m, n, image, old , color);
        vector<vector<int>>visited(m,vector<int>(n,0));
        
       // memset(visited, false, sizeof(visited));
        
       queue<pair<int,int>>q;
        q.push({sr,sc});
        
        int dx[4] = {1,-1,0,0};
        int dy[4] = {0,0,1,-1};
        
        while(!q.empty()){
            
            auto it = q.front();
            q.pop();
             image[it.first][it.second] = color;
            for(int i=0; i<4; i++){
                int x = it.first + dx[i];
                int y = it.second + dy[i];
                
                if(x>=0 && y>=0 && x<m && y<n && image[x][y] == old && !visited[x][y]){
                   
                    q.push({x,y});
                    visited[x][y] = 1;
                }
            }
        }
        
        return image;
    }
};