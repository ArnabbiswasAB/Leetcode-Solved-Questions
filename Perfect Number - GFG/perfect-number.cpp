//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
    int factorial(int N){
     
     if(N == 0)
     return 1;
     
     return factorial(N-1) * N;
    }
    
    int isPerfect(int N) {
        // code here
        
        int ans = 0, NN = N;
        
        while(N){
            int val = N%10;
            N/=10;
            
            ans += factorial(val);
        }
        
        return ans == NN;
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int N;
        cin >> N;
        Solution ob;
        cout << ob.isPerfect(N) << "\n";
    }
}

// } Driver Code Ends