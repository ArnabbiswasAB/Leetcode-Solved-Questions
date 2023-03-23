//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
public:
    
    long long dp[101][101][101];
long long solve(vector<vector<int>>& grid, int sum,
int i, int j, const int& n, const int& k)

{
    
if(sum > k)
return 0;

if(i==n-1 && j==n-1)
{
if(sum + grid[i][j] == k)
return 1;

return 0;
}

if(dp[i][j][sum] != -1) return dp[i][j][sum];

long long paths = 0;
if(i+1 < n) paths += solve(grid, sum + grid[i][j], i+1, j, n, k);
if(j+1 < n) paths += solve(grid, sum + grid[i][j], i, j+1, n, k);

return dp[i][j][sum] = paths;
}

    
    long long numberOfPath(int n, int k, vector<vector<int>> arr){
        
       memset(dp, -1, sizeof(dp));
       return solve(arr, 0, 0, 0, n, k);

    }
};

//{ Driver Code Starts.

int main()
{
    Solution obj;
    int i,j,k,l,m,n,t;
    cin>>t;
    while(t--)
    {
        cin>>k>>n;
        vector<vector<int>> v(n+1, vector<int>(n+1, 0));
        for(i=0;i<n;i++)
            for(j=0;j<n;j++)
                cin>>v[i][j];
        cout << obj.numberOfPath(n, k, v) << endl;
    }
}
// } Driver Code Ends