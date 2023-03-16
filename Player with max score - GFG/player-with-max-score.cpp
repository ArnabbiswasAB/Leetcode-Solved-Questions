//{ Driver Code Starts
//Initial template for C++

#include<bits/stdc++.h> 
using namespace std; 

// } Driver Code Ends
//User function Template for C++

class Solution{   
public:
    int helper(int arr[], int s, int e, vector<vector<int>> &dp){
        
        if(s>e)
        return 0;
        
        if(dp[s][e] != -1)
        return dp[s][e];
        
        int op1 = arr[s] + min(helper(arr,s+2,e,dp), helper(arr,s+1,e-1,dp));
        int op2 = arr[e] + min(helper(arr,s+1,e-1,dp), helper(arr,s,e-2,dp));
        
        return dp[s][e] = max(op1,op2);
    }
    
    
    bool is1winner(int N,int arr[]) {
        
        // code here
        int sum = 0;
        for(int i=0; i<N; i++){
            sum += arr[i];
        }
        
        vector<vector<int>> dp(N, vector<int>(N,-1));
        int p1 =  helper(arr,0,N-1,dp);
        
        if(p1 >= (sum - p1))
        return true;
        
        return false;
    }
};

//{ Driver Code Starts.
int main() 
{ 
    int t;
    cin>>t;
    while(t--)
    {
        int N, X;
        cin >> N;
        int arr[N];
        for(int i = 0; i < N; i++){
            cin >> arr[i];
        }
        
        Solution ob;
        cout << ob.is1winner(N, arr) << endl;
    }
    return 0; 
} 

// } Driver Code Ends