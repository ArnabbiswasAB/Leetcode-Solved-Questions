//{ Driver Code Starts
//Initial template for C++

#include <bits/stdc++.h>
#include <unordered_map>
using namespace std;

// } Driver Code Ends
//User function template for C++

class Solution {
public:
    int longestCommonSum(bool arr1[], bool arr2[], int n) {
            // code here 
            
            unordered_map<int,int>mp;
            mp[0]=-1;
            int ans = 0;
            int x = 0, y = 0;
            
            for(int i=0; i<n; i++){
                
                x += arr1[i];
                y += arr2[i];
                
                int diff = x - y;
                
                if(mp.find(diff) == mp.end()){
                    mp[diff] = i;
                }else
                   ans = max(ans, i - mp[diff]);
            }
            
            return ans;
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, i;
        cin >> n;
        bool arr1[n], arr2[n];
        for (i = 0; i < n; i++) {
            cin >> arr1[i];
        }
        for (i = 0; i < n; i++) {
            cin >> arr2[i];
        }
        Solution ob;
        auto ans = ob.longestCommonSum(arr1, arr2, n);
        cout << ans << "\n";
    }
    return 0;
}
// } Driver Code Ends