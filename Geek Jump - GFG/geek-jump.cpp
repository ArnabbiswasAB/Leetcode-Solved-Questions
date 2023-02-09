//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
  
  int solve(int n, vector<int>& height, vector<int>& dp)
    {
        // step 1 : create the array of vector of size n+1;
        
        if(n == 0)
        {
            return 0;
        }
        
        // step 3: check it is precomputed or not
        if(dp[n] != -1)
        {
            return dp[n];
        }
        
        int left = solve(n-1, height, dp) + abs(height[n] - height[n-1]);
        int right = INT_MAX;
        
        if(n > 1)
        {
            right = solve(n-2, height, dp) + abs(height[n] - height[n-2]);
        }
        
        // store it into the dp vector and then return;
        return dp[n] = min(left, right);
        
    }
    int minimumEnergy(vector<int>& height, int n) {
        
        // step 1 : create the array of vector of size n+1
        vector<int>dp(n+1, -1);
        
        return solve(n-1, height, dp);
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int N;
        cin >> N;
        vector<int> arr(N);
        for (int i = 0; i < N; i++) {
            cin >> arr[i];
        }
        Solution obj;
        cout << obj.minimumEnergy(arr, N) << "\n";
    }
    return 0;
}
// } Driver Code Ends