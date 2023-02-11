//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution{
  public:
/*You are required to complete this method*/
    bool f(int i, int j, string p, string s, vector<vector<int>>& dp){
       
       if(i<0 && j<0)
       return true;
       if(i<0 && j>=0)
       return false;
       if(j<0 && i>=0){
           for(int k=i; k>=0; k--){
               if(p[k] != '*')
               return false;
           }
           return true;
       }
       
       if(dp[i][j] != -1)
       return dp[i][j];
       
       
       if(p[i] == s[j] || p[i] == '?')
         return dp[i][j] = f(i-1,j-1,p,s,dp);
         
         
        if(p[i] == '*'){
            return dp[i][j] = f(i,j-1,p,s,dp) || f(i-1,j,p,s,dp);
        } 
        
        return dp[i][j] = false;
    }
    
    
    bool allstar(string p, int i){
       
       for(int k=i; k>=0; k--){
           if(p[i] != '*')
           return false;
       }    
       
       return true;
    }
    
    bool x(string p,int j){
        for(int k=1;k<=j;k++){
                if(p[k-1]!='*'){
                    return false;
                }
            }
            return true;
    }
    
    int wildCard(string p,string s)
    {
       int n=p.size();
		int m=s.size();
		vector<vector<bool>> dp(n+1,vector<bool>(m+1,false));
		dp[0][0]=true;
		for(int j=1;j<=m;j++) dp[0][j]=false;
		for(int i=1;i<=n;i++){
			bool flag=true;
			for(int k=1;k<=i;k++){
				if(p[k-1]!='*'){
					flag=false;
					break;
				}
			}
			dp[i][0]=flag;
		}
		for(int i=1;i<=n;i++){
			for(int j=1;j<=m;j++){
				if(p[i-1]==s[j-1] || p[i-1]=='?') dp[i][j]=dp[i-1][j-1];
				else if(p[i-1]=='*') dp[i][j]=dp[i-1][j] || dp[i][j-1];
				else dp[i][j]=false;
			}
		}
		return dp[n][m];
    }
};

//{ Driver Code Starts.
int main()
{
   int t;
   cin>>t;
   while(t--)
   {
           string pat,text;
           cin>>pat;
cin.ignore(numeric_limits<streamsize>::max(),'\n');
           cin>>text;
           Solution obj;
           cout<<obj.wildCard(pat,text)<<endl;
   }
}

// } Driver Code Ends