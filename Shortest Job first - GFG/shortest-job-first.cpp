//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

// Back-end complete function Template for C++

class Solution {
  public:
    int solve(vector<int>& bt) {
        // code here
           sort(bt.begin(),bt.end());

        int n=bt.size();

        int prefix[n];

        int sum=0;

        for(int i=0;i<bt.size()-1;i++)

        {

            if(i==0)

            prefix[i]=bt[i];

            else

            prefix[i]=prefix[i-1]+bt[i];

        }

        for(int i=0;i<n-1;i++)

        {

            sum+=prefix[i];

        }

        return sum/n;
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<int> bt(n), p(n);
        for (int i = 0; i < n; i++) {
            cin >> bt[i];
        }
        Solution obj;
        int ans = obj.solve(bt);
        cout << ans << "\n";
    }
    return 0;
}
// } Driver Code Ends