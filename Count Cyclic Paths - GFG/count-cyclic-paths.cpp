//{ Driver Code Starts
//Initial Template for C++

#include<bits/stdc++.h> 
using namespace std; 

// } Driver Code Ends
//User function Template for C++

class Solution{   
public:
    int countPaths(int N){
    
     if(N==1){
	        return 0;
	    }
	    if(N==2){
	        return 3;
	    }
	    
	    long long mod=1000000007;
	    
		long long dp[N+1];
		
		//store inital seq
		dp[1]=0;
		dp[2]=3;
		long num=3;
		
		for(int i=3; i<=N; i++){
		   num=(num*3) % mod;
		   dp[i]=((num) - (dp[i-1]) + mod) % mod;
		}
		
		int res=(int)(dp[N] % mod);
		
		return res;
    
    }
};

/*
Explanation:-for every node,we can go to 3 other 
nodes.So without any constraint,the answer would be 3^n.
Now,let us fix the final node[let it be any node including origin].
So we would be devoid of last move so total answer will be 3^(n-1).
Now if we fix the final node as origin,we have to ensure that
we should be at node other than origin at (n-1)th step(obvious).
so we have to remove all those steps in which we are at origin 
at (n-1)th step.This is possible if we subtract our original 
3^(n-1) answer with previous answer.We can use hashing for this.

int countPaths(int N){
        if(N == 1)
            return 0;
        int M = 1e9+7;
        
        vector<long long> prev(4,0);
        prev[0] = 1;
        for(int i = 1; i <= N; i++) {
            vector<long long> cur(4,0);
            cur[0] = (prev[1]+prev[2]+prev[3])%M;
            cur[1] = (prev[2]+prev[3]+prev[0])%M;
            cur[2] = (prev[3]+prev[0]+prev[1])%M;
            cur[3] = (prev[0]+prev[1]+prev[2])%M;
            
            prev = cur;
        }
        
        return prev[0];
    }
*/

//{ Driver Code Starts.
int main() 
{ 
    int t;
    cin>>t;
    while(t--)
    {
        int N;
        cin >> N;
        
        Solution ob;
        cout << ob.countPaths(N) << endl;
    }
    return 0; 
}

// } Driver Code Ends