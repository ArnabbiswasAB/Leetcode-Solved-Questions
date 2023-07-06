//{ Driver Code Starts
//Initial template for C++

#include<bits/stdc++.h> 
using namespace std; 

// } Driver Code Ends
//User function template for C++

class Solution{   
public:
    bool helper(vector<int>& arr, int ind, int sum, vector<vector<int>>& dp){
        
        if(sum == 0)
        return 1;
        
        if(ind == 0){
            if(sum == arr[0])
            return 1;
            
            return 0;
        }
        
        if(dp[ind][sum] != -1)
        return dp[ind][sum];
        
        bool notTake = helper(arr, ind-1, sum, dp);
        bool take = false;
        
        if(arr[ind] <= sum)
           take = helper(arr, ind-1, sum - arr[ind], dp);
           
        return dp[ind][sum] = notTake || take;   
    }
    
    
    bool isSubsetSum(vector<int>arr, int sum){
        // code here 
        int n = arr.size();
        vector<vector<int>> dp(n, vector<int>(sum+1,-1));
        
        return helper(arr, n-1, sum, dp);
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