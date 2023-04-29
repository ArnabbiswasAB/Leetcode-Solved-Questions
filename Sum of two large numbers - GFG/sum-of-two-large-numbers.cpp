//{ Driver Code Starts

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function template for C++
class Solution {
  public:
    string findSum(string X, string Y) {
        // Your code goes here
        
        string ans = "";
        int i = X.size()-1, j = Y.size()-1, carry = 0;
        
        while(i>=0 || j>=0 || carry){
            
            if(i>=0)
            carry += (X[i--] - '0');
            
            if(j>=0)
            carry += (Y[j--] - '0');
            
            ans += (carry%10 + '0');
            carry /= 10;
        }
        
        
        reverse(ans.begin(),ans.end());
        
        while(ans.size()>1 && ans[0] == '0'){
            ans.erase(ans.begin());
        }
        
        
        return ans;
    }
};

//{ Driver Code Starts.

int main() {

    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    cout.tie(NULL);

    int t;
    cin >> t;
    while (t--) {
        string x, y;
        cin >> x >> y;
        Solution ob;
        cout << ob.findSum(x, y) << "\n";
    }

    return 0;
}
// } Driver Code Ends