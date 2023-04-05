//{ Driver Code Starts
//Initial Template for C++


#include<bits/stdc++.h> 
using namespace std; 


// } Driver Code Ends
//User function Template for C++

class Solution {
public:
    int helpaterp(vector<vector<int>> grid)
    {
        //code here
        
        queue<pair<int,int>>q;
        int total = 0, m = grid.size(), n = grid[0].size(), count = 0, times = 0;
        
        for(int i=0; i<m; i++){
            for(int j=0; j<n; j++){
                
                if(grid[i][j] == 2)
                {
                    q.push({i,j});
                    total++;
                }else if(grid[i][j] == 1){
                    total++;
                }
            }
        }
        
        int dx[4] = {1,-1,0,0};
        int dy[4] = {0,0,1,-1};
        
        while(!q.empty()){
            
            int k = q.size();
            count += k;
            
            for(int i=0; i<k; i++){
                
                auto it = q.front();
                q.pop();
                
                for(int i=0; i<4; i++){
                    
                    int x = it.first + dx[i];
                    int y = it.second + dy[i];
                    
                    if(x<0 || y<0 || x>=m || y>=n || grid[x][y] != 1)
                    continue;
                    
                    q.push({x,y});
                    grid[x][y] = 2;
                }
            }
            
            if(!q.empty())
            times++;
        }
        
        if(total == count)
        return times;
        
        return -1;
    }
};


//{ Driver Code Starts.


int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int R;int C;
        
        cin>>R>>C;
        vector<vector<int>> hospital;
        int i,j;
        for(i=0;i<R;i++)
         {   vector<int> temp;
             for(j=0;j<C;j++)
            {
                int k;
                cin>>k;
                temp.push_back(k);
            }
            hospital.push_back(temp);
         }
        
        Solution ob;
        int ans = ob.helpaterp(hospital);
        cout << ans << endl;
    }
    return 0;
}
// } Driver Code Ends