//{ Driver Code Starts
#include <bits/stdc++.h>

using namespace std;


// } Driver Code Ends
//User function template for C++
class Solution{
public:	
	// Function to find length of longest bitonic
	// subarray
	int bitonic(vector<int> arr, int n) {
	    // code here
	    
	   
        int inc[n];
        int dec[n];
        int i, max;
        inc[0] = 1;
        dec[n-1] = 1;
        for (i = 1; i < n; i++)
        inc[i] = (arr[i] >= arr[i-1])? inc[i-1] + 1: 1;
     
        for (i = n-2; i >= 0; i--)
        dec[i] = (arr[i] >= arr[i+1])? dec[i+1] + 1: 1;

        max = inc[0] + dec[0] - 1;
        for (i = 1; i < n; i++)
            if (inc[i] + dec[i] - 1 > max)
                max = inc[i] + dec[i] - 1;
     
        return max;
	}
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<int> arr(n);
        for (int i = 0; i < n; i++) {
            cin >> arr[i];
        }
        Solution ob;
        auto ans = ob.bitonic(arr, n);
        cout << ans << "\n";
    }
    return 0;
}
// } Driver Code Ends