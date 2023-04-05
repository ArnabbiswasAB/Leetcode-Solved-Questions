//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution{
	public:

	int lis(vector<int> &nums, int n) {
        int dp[n];
        dp[0] = 1;
        for (int i = 1; i < n; i++) {
            dp[i] = 1;
            for (int j = 0; j < i; j++) {
                if (nums[j] < nums[i] 
                    && dp[i] < 1 + dp[j]
                    && (i - j) <= nums[i] - nums[j]) {
                    dp[i] = 1 + dp[j];
                }
            }
        }
        int ans = 1;
        for (int i = 0; i < n; i++) {
            ans = max(ans, dp[i]);
        }
        return ans;
    }

public:

    int min_operations(vector<int> &nums) {
        // Code here
        int n = nums.size();
        return n - lis(nums, n);
    }
};

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n;
		cin >> n;
		vector<int>nums(n);
		for(int i = 0; i < n; i++)cin >> nums[i];
		Solution ob;
		int ans  = ob.min_operations(nums);
		cout << ans <<"\n";
	}
	return 0;
}
// } Driver Code Ends