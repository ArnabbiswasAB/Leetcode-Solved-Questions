//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
public:
    int helper(int i,int j,vector<int>& nums, vector<vector<int>>& dp){
        
        if(i>j)
        return 0;
        
        if(dp[i][j] != -1)
        return dp[i][j];
        
        int maxi = INT_MIN;
        
        for(int k=i; k<=j; k++){
            int cost = nums[i-1]*nums[k]*nums[j+1] + 
            helper(i,k-1,nums,dp) + helper(k+1,j,nums,dp);
            
            maxi = max(maxi, cost);
        }
        
        return dp[i][j] = maxi;
    }
    
    int maxCoins(int N, vector<int> &arr) {
        
        arr.insert(arr.begin(),1);
        arr.push_back(1);
        vector<vector<int>> dp(N+1, vector<int>(N+1,-1));
        return helper(1,N,arr,dp);
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int N;
        cin>>N;
        
        vector<int> arr(N);
        for(int i=0; i<N; i++)
            cin>>arr[i];

        Solution obj;
        cout << obj.maxCoins(N, arr) << endl;
    }
    return 0;
}
// } Driver Code Ends