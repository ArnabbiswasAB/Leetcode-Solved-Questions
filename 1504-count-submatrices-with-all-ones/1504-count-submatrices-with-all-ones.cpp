class Solution {
public:
     int numSubmat(vector<vector<int>>& mat) {
        
        int n = mat.size();
        
        int m = mat[0].size();
        
        int ans = 0;
        
        //precalculation of count of 1's
        
        for(int i = 0; i < n; i++)
        {
            int count = 0;
            
            for(int j = m - 1; j >= 0; j--)
            {
                if(mat[i][j])
                {
                    count++;
                }
                
                else
                {
                    count = 0;
                }
                
                mat[i][j] = count;
            }
        }
        
        for(int i = 0; i < n; i++)
        {
            for(int j = 0; j < m; j++)
            {
                int temp = INT_MAX;
                
                for(int k = i; k < n; k++)
                {
                    temp = min(temp, mat[k][j]);
                    
                    ans += temp;
                }
            }
        }
        
        return ans;
    }
};