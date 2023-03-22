//{ Driver Code Starts
//Initial template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function template for C++

class Solution{   
public:
    int lengthOfLongestAP(int A[], int n) {
        // code here
        
   //using map to serach element;
     unordered_map<int ,int> mep;
     for(int i=0; i<n; i++){
         mep[A[i]]++;
     }
     
     int ans=1;//for corner case:when n=1
     
     for(int i=0; i<n-1; i++){
         int count;
         for(int j=i+1; j<n; j++){
             int cd=A[j]-A[i];//common diffrence
             count=2;
             int curr=A[j];
             /*serching for succesive element of 	   progression in the map with current cd*/
             while(mep[cd+curr]!=0){
                 count++;
                 curr+=cd;
             }
             ans=max(ans,count);
         }
     }
     return ans;
        
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        int A[n];
        for (int i = 0; i < n; i++) {
            cin >> A[i];
        }
        Solution ob;
        auto ans = ob.lengthOfLongestAP(A, n);
        cout << ans << "\n";
    }
    return 0;
}
// } Driver Code Ends