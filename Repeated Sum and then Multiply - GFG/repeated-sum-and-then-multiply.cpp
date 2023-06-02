//{ Driver Code Starts
//Initial Template for C++
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function Template for C++
class Solution {
  public:
    int repeatedSumMul(int n) 
    {
        
        int prev = 0;
        
        while(n > 9){
            
            int temp = 0;
            prev = n;
            
            while(n != 0){
                temp += n % 10;
                n/=10;
            }
            
            n = temp;
        }
        
        int prod = 1;
        while(prev){
            
            int temp = prev%10;
            prod *= temp;
            prev/=10;
        }
        
        return prod;
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int  n;
        cin >> n ;
        Solution ob;
        cout<<ob.repeatedSumMul(n)<<endl;
    }
    return 0;
}

// } Driver Code Ends