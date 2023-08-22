//{ Driver Code Starts
#include <bits/stdc++.h>

using namespace std;

// } Driver Code Ends
class Solution {
  public:
  
   void pattern1(int n){
       
       for(int i=n-1; i>=0; i--){
           
           for(int j=0; j<=n-i-1; j++)
           cout<<"*";
           
           for(int j=0; j<2*i; j++)
           cout<<" ";
           
           for(int j=0; j<=n-i-1; j++)
           cout<<"*";
           
           cout<<endl;
       }
   }
   
   void pattern2(int n){
       
       for(int i=0; i<n; i++){
           
           if(i == 0)
           continue;
           
           for(int j=0; j<=n-i-1; j++)
           cout<<"*";
           
           for(int j=0; j<2*i; j++)
           cout<<" ";
           
           for(int j=0; j<=n-i-1; j++)
           cout<<"*";
           
           cout<<endl;
       }
   }
   
    void printTriangle(int n) {
       
       pattern1(n);
       pattern2(n);
        
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