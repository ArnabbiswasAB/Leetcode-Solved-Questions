//{ Driver Code Starts
//Initial template for C++
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function template for C++

class Solution{   
public:
    long long maxProduct(int arr[], int n) {
        // code here
        
        if(n >= 3) {
            int firstMax = INT_MIN, secondMax = INT_MIN, thirdMax = INT_MIN;
            int firstMin = INT_MAX, secondMin = INT_MAX;
            for(int i=0;i<n;++i) {
                // Logic for finding first, second and third maximum numbers
                if(arr[i] > firstMax) {
                    thirdMax = secondMax;
                    secondMax = firstMax;
                    firstMax = arr[i];
                }
                else if(arr[i] > secondMax) {
                    thirdMax = secondMax;
                    secondMax = arr[i];
                }
                else if(arr[i] > thirdMax) {
                    thirdMax = arr[i];
                }
                // Logic for finding first and second minimum numbers
                if(arr[i] < firstMin) {
                    secondMin = firstMin;
                    firstMin = arr[i];
                }
                else if(arr[i] < secondMin) {
                    secondMin = arr[i];
                }
            }
            return (long)max( (long) firstMin * secondMin * firstMax, (long) firstMax * secondMax * thirdMax);
        }
        return 0;
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        int arr[n];
        for (int i = 0; i < n; i++) {
            cin >> arr[i];
        }
        Solution ob;
        auto ans = ob.maxProduct(arr, n);
        cout << ans << "\n";
    }
    return 0;
}
// } Driver Code Ends