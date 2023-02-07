//{ Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//Back-end complete function Template for C++

class Solution {
  public:
   int f(int ind,vector<int>& nums,int target,vector<vector<int>>& dp){
       
       if(ind == 0){
           if(nums[0] == 0 && target == 0)
           return 2;
           else if(nums[0] == target || target == 0)
           return 1;
           
           return 0;
       }
       
       if(dp[ind][target] != -1)
       return dp[ind][target];
       
       int notTaken = f(ind - 1, nums, target, dp);
       int taken = 0;
       if(nums[ind] <= target)
          taken = f(ind - 1, nums, target - nums[ind], dp);
          
        
       return dp[ind][target] = taken + notTaken;          
   }
   
   
   
    int findTargetSumWays(vector<int>&A ,int target) {
        //Your code here
        
        int total = 0, n = A.size();
        for(int i=0; i<A.size(); i++){
            total += A[i];
        }
        
        if(total - target < 0)
        return 0;
        if((total - target)% 2 == 1)
        return 0;
        
        int s1 = (total - target)/2;
        vector<vector<int>> dp(n, vector<int>(s1+1,-1));
        return f(n-1,A, s1, dp);
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int N;
        
        cin>>N;
        vector<int>arr(N);
        
        for(int i=0 ; i<N ; i++){
            cin>>arr[i];
        }
        int target;
        cin >> target;

        Solution ob;
        cout<<ob.findTargetSumWays(arr,target);
        cout<<"\n";
    }
    return 0;
}
// } Driver Code Ends