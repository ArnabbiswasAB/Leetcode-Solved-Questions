//{ Driver Code Starts
#include <bits/stdc++.h>

using namespace std;

// } Driver Code Ends
class Solution {
  public:
    void printTriangle(int n) {
        // code here
        
        for(int i=0; i<n; i++){
            
            char ch = 'A' +(n-1);
            
            for(int j=0; j<=i; j++){
                cout<<ch<<" ";
                ch--;
            }
            
            cout<<endl;
        }
        
        return;
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;

        Solution ob;
        ob.printTriangle(n);
    }
    return 0;
}
// } Driver Code Ends