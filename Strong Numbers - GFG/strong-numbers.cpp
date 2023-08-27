//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
    int factorial(int n){
        
         int fact = 1;
   for (int i = 1; i <= n; i++) {
      fact = fact * i;
   }
   return fact;
    }
    
    int isStrong(int N) {
        // code here
        
        int sum = 0, NN = N;
        
        while(N){
            int val = N%10;
            N/=10;
            
            sum += factorial(val);
        }
        
        return sum == NN && NN != 0;
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int N;
        
        cin>>N;

        Solution ob;
        cout << ob.isStrong(N) << endl;
    }
    return 0;
}
// } Driver Code Ends