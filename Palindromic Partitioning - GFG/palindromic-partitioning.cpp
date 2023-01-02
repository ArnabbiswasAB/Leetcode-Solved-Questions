//{ Driver Code Starts
// Initial Template for c++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution{
public:
    
    bool palin(int i, int j, string s){
     
     while(i<=j){
         if(s[i] != s[j])
         return false;
         
         i++;
         j--;
     }
     
     return true;
    } 
    
    
    
    int f(string &str,int ind,int n, vector<int>& dp){
       
       if(ind == str.size())
       return 0;
       
       if(dp[ind] != -1)
       return dp[ind];
       
       
       int ans = INT_MAX;
       for(int k = ind; k<n; k++){
           
           if(palin(ind,k,str)){
               
               int cost = 1 + f(str,k+1,n,dp);
               ans = min(ans,cost);
           }
       }
       return dp[ind] = ans;
    }
    
    
    int palindromicPartition(string str)
    {
        // code here
        
        vector<int>dp(str.size(),-1);
        return f(str,0,str.size(),dp) - 1;
    }
};

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        string str;
        cin>>str;
        
        Solution ob;
        cout<<ob.palindromicPartition(str)<<"\n";
    }
    return 0;
}
// } Driver Code Ends