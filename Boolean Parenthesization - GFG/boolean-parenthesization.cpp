//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution{
public:


 long long mod=1e3+3;

    int helper(int n,string s,int i,int j,bool isTrue,vector<vector<vector<int>>>&dp){

        if(i>j){

            return false;

        }

        if(i==j){

            if(isTrue==true){

                return s[i]=='T';

            }else{

                return s[i]=='F';

            }

        }

        if(dp[i][j][isTrue]!=-1){

            return dp[i][j][isTrue];

        }

        int count=0;

        for(int k=i+1;k<j;k+=2){

            int lt=helper(n,s,i,k-1,true,dp);

            int lf=helper(n,s,i,k-1,false,dp);

            int rt=helper(n,s,k+1,j,true,dp);

            int rf=helper(n,s,k+1,j,false,dp);

            

            if(s[k]=='^'){

                if(isTrue==true){

                count+=((lt*rf)%mod+(rt*lf)%mod)%mod;

                }else{

                    count+=((lt*rt)%mod+(lf*rf)%mod)%mod;

                }

            }else if(s[k]=='&'){

                if(isTrue==true){

                count+=(lt*rt)%mod;

                }else{

                    count+=((lt*rf)%mod+(lf*rt)%mod+(lf*rf)%mod)%mod;

                }

            }else if(s[k]=='|'){

                if(isTrue==true){

                count+=((lt*rf)%mod + (lf*rt)%mod + (lt*rt)%mod)%mod;

                }else{

                    count+=(lf*rf)%mod;

                }

            }

        }

        dp[i][j][isTrue]=count;

        return count%mod;

    }

    int countWays(int N, string S){

        // code here

        int i=0;

        int j=N-1;

        vector<vector<vector<int>>>dp(N+1,vector<vector<int>>(N+1,vector<int>(2,-1)));

        return helper(N,S,i,j,true,dp);

        

    }

};

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int N;
        cin>>N;
        string S;
        cin>>S;
        
        Solution ob;
        cout<<ob.countWays(N, S)<<"\n";
    }
    return 0;
}
// } Driver Code Ends