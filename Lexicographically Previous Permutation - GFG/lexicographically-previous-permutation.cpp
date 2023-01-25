//{ Driver Code Starts
// Initial Template for C++
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++
class Solution {
  public:
    string prevPermutation(string str) {
        // code here
        
         int n = str.length() - 1;
 
    // Find largest index i such that str[i - 1] >
    // str[i]
    int i = n;
    while (i > 0 && str[i - 1] <= str[i])
        i--;
 
    // if string is sorted in ascending order
    // we're at the last permutation
    if (i <= 0)
        return str;
 
    // Note - str[i..n] is sorted in ascending order
 
    // Find rightmost element's index that is less
    // than str[i - 1]
    int j = i - 1;
    while (j + 1 <= n && str[j + 1] < str[i - 1])
        j++;
 
    // Swap character at i-1 with j
    swap(str[i - 1], str[j]);
 
    // Reverse the substring [i..n]
    reverse(str.begin() + i, str.end());
 
    return str;
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        string s;
        cin >> s;
        Solution ob;
        cout<<ob.prevPermutation(s)<<endl;
    }
    return 0;
}

// } Driver Code Ends