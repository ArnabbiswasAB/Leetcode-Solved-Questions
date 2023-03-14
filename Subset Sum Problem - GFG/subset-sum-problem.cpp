//{ Driver Code Starts
//Initial template for C++

#include<bits/stdc++.h> 
using namespace std; 

// } Driver Code Ends
//User function template for C++

class Solution{   
public:
    bool helper(int i, vector<int>& arr, int sum, vector<vector<int>> &dp){
        
        if(sum == 0)
        return true;
        
        if(i == 0){
           return arr[0] == sum;
        }
        
        if(dp[i][sum] != -1)
        return dp[i][sum];
        
        bool notTaken = helper(i-1,arr,sum, dp);
        bool taken = false;
        
        if(arr[i] <= sum)
        taken = helper(i-1,arr, sum - arr[i], dp);
        
        
        return dp[i][sum] = notTaken || taken;
    }
    
    
    bool isSubsetSum(vector<int>arr, int sum){
        // code here 
        int n = arr.size();
        vector<vector<int>> dp(n, vector<int>(sum+1, 0));
      //  return helper(n-1,arr,sum,dp);
      
      for(int i = 0; i<sum+1; i++){
          if(arr[0] == i)
             dp[0][i] = true;
      }
      
      dp[0][0] = true;
      
      
      for(int i=1; i<n; i++){
          for(int j=0; j<sum+1; j++){
              
              bool notTaken = dp[i-1][j];
              bool take = false;
              
              if(arr[i] <= sum)
                 take = dp[i-1][j-arr[i]];
                 
               dp[i][j] = notTaken || take;     
          }
      }
      
      
      return dp[n-1][sum];
    }
};

//{ Driver Code Starts.
int main() 
{ 
    int t;
    cin>>t;
    while(t--)
    {
        int N, sum;
        cin >> N;
        vector<int> arr(N);
        for(int i = 0; i < N; i++){
            cin >> arr[i];
        }
        cin >> sum;
        
        Solution ob;
        cout << ob.isSubsetSum(arr, sum) << endl;
    }
    return 0; 
} 

// } Driver Code Ends