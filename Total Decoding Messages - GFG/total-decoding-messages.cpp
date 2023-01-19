//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
	public:
	int mod = 1e9+7;
	
	int solve(string& s, int i, vector<int>& dp) {
    // base case
    if (i >= s.length()) return 1;
    
    if (dp[i] != -1) return dp[i];
    
    int ans = 0;
    // we want to check atmost 2 characters because,
    // the max value we are looking for is 26. Hence a loop is not required.
    if (s[i] == '0') {
        ans = 0;
    } else {
        // check for single digit
        ans += solve(s, i + 1, dp) % mod;
        // check for 2 digits
        if (i + 1 < s.length() && (s[i] == '1' || (s[i] == '2' && s[i + 1] <= '6'))) {
            ans += solve(s, i + 2, dp) % mod;
        }
    }
    return dp[i] = ans % mod;
}
	
	
		int CountWays(string s){
		    // Code here
		    
		    int n = s.size();
		    vector<int>dp(n,-1);
		    return solve(s,0,dp);
		}

};

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		string str;
		cin >> str;
		Solution obj;
		int ans = obj.CountWays(str);
		cout << ans << "\n";
	}
	return 0;
}
// } Driver Code Ends