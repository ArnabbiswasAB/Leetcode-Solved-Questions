//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function template for C++

class Solution{
  public:	

	int distinctSubsequences(string str)
	{
	    // Your code goes here
	 
        int n = str.size();
        
        long long mod = 1e9 + 7;
        
        // dp[i] will store the unique subsequence till (i - 1)th character
        
        vector<int> dp(n + 1, 0);
        
        dp[0] = 1;
        
        // mp will store the last occurance of character, wrt. indexing of dp
        
        unordered_map<char, int> mp;
        
        for(int i = 1; i <= n; i++)
        {
            // first of all double the count of subsequence
            
            dp[i] = (2 % mod * dp[i - 1] % mod) % mod;
            
            char ch = str[i - 1];
            
            // remove the common subsequence
            
            // if character is repeating, then substract the common subsequence
            
            if(mp.count(ch))
            {
                int last_idx = mp[ch];
                
                // since dp[i] is greater than dp[last_idx - 1], so dp[i] % mod can be smaller than dp[last_idx - 1] % mod, to avoid negative value we will add mod
                
                dp[i] = (dp[i] % mod - dp[last_idx - 1] % mod  + mod) % mod;
            }
            
            // update the last occurance of ch
            
            mp[ch] = i;
        }
        
        // exclude the empty subsequence i.e ("")
      
        return dp[n];
    }
	
};

//{ Driver Code Starts.

int main() 
{
   	

   	ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    cout.tie(NULL);
   
   	int t;
   	cin >> t;
   	while(t--)
   	{
   		string s;
   		cin >> s;

        Solution ob;
   		cout << ob.distinctSubsequences(s) << "\n";
   	}

    return 0;
}
// } Driver Code Ends