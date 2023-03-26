//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
    double waterOverflow(int k, int r, int c) {
        // code here
        
        vector<vector<double>> dp(k+1,vector<double>(k+1));
       dp[0][0]=k;
       for(int i=0;i<k;i++)
       {
           for(int j=0;j<=i;j++)
           {
               if(dp[i][j]>1.0)
               {
                   double spare = dp[i][j]-1.0;
                   dp[i][j]=1.0;
                   dp[i+1][j]+=spare/2.0;
                   dp[i+1][j+1]+= spare/2.0;
               }
           }
       }
       return dp[r-1][c-1];
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int K,R,C;
        
        cin>>K>>R>>C;

        Solution ob;
        cout << fixed << setprecision(6)<< ob.waterOverflow(K,R,C) << endl;
    }
    return 0;
}
// } Driver Code Ends