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
        dfs(sr, sc, m, n, image, old , color);
        return image;
    }
};