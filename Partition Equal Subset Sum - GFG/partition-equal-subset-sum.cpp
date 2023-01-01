//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution{
public:
    int equalPartition(int N, int arr[])
    {
        // code here
        int sum = 0;
        for(int i=0; i<N; i++){
            sum += arr[i];
        }
        
        if(sum % 2 != 0)
        return 0;
        
        int target = sum/2;
        vector<vector<bool>>dp(N,vector<bool>(sum/2 + 1, false));
        
        for(int i=0; i<N; i++)
          dp[i][0] = true;
          
        if(arr[0]<= target)
          dp[0][arr[0]] = true;
          
        for(int i=1; i<N; i++){
            for(int j=1; j<=target; j++){
                
                bool notTaken = dp[i-1][j];
                bool Taken = false;
                
                if(arr[i]<=j)
                 Taken = dp[i-1][j - arr[i]];
                 
                 dp[i][j] = notTaken||Taken;
            }
        }
        
        return dp[N-1][target];
    }
};

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int N;
        cin>>N;
        int arr[N];
        for(int i = 0;i < N;i++)
            cin>>arr[i];
        
        Solution ob;
        if(ob.equalPartition(N, arr))
            cout<<"YES\n";
        else
            cout<<"NO\n";
    }
    return 0;
}
// } Driver Code Ends