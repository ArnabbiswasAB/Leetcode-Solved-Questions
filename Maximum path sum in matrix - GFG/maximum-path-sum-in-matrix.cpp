//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution{
public:
    int maximumPath(int N, vector<vector<int>> mat)
    {
        // code here
        
        int dp[N][N];
        
        for(int i=0; i<N; i++)
        {
            dp[0][i] = mat[0][i];
        }
        
        for(int i=1; i<N; i++){
            for(int j=0; j<N; j++){
                
                int up = mat[i][j] + dp[i-1][j];
                
                int left = mat[i][j];
                if(j-1>=0)
                left += dp[i-1][j-1];
                else
                left +=  -1e9;
                
                int right = mat[i][j];
                if(j+1<N)
                right += dp[i-1][j+1];
                else
                right += -1e9;
                
                dp[i][j] = max(up,max(left,right));
            }
        }
        
        
        int maxi = INT_MIN;
        for(int i=0; i<N; i++){
            maxi = max(maxi,dp[N-1][i]);
        }
        
        return maxi;
    }
};

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int N;
        cin>>N;
        vector<vector<int>> Matrix(N, vector<int>(N, 0));
        for(int i = 0;i < N*N;i++)
            cin>>Matrix[(i/N)][i%N];
        
        Solution ob;
        cout<<ob.maximumPath(N, Matrix)<<"\n";
    }
    return 0;
}
// } Driver Code Ends