//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++

class Solution {
  public:
   int lis(vector<int> v)
 {
     vector<int> lis;
     
     for(int i=0;i<v.size();i++)
     {
          auto it = lower_bound(lis.begin(), lis.end(), v[i]);
         if(it!=lis.end())
         *it=v[i];
         else
         lis.push_back(v[i]);
     }
     return lis.size();
 }
 
    int minInsAndDel(int A[], int B[], int N, int M) {
        // code here
      vector<int> v;
        unordered_set<int> s;
        
        for(int i=0;i<M;i++){
            s.insert(B[i]);
        }
        
        for(int i=0;i<N;i++){
            if(s.find(A[i])!=s.end()){
                v.push_back(A[i]); 
       // Notice, we are pushing common elements of A and B
            }
        }
        
        int LCS=lis(v);
        
        return N+M-(2*LCS);
    }
    
    /*
    This is a question of Longest increasing subsequence. First delete all the element in array A which is not present in array B.

Get the count of all deleted element.

Now find the Longest increasing subsequence of new Array A. You will get the length of subsequence, subtract it from the length of new array A, and answer which is produced, add it in the count of deleted element.

At last, subtract the length of Longest increasing subsequence of new array A from array B, and add the result into count of all deleted element.
    */
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int N,M;
        cin>>N>>M;
        
        int A[N], B[M];
        for(int i=0; i<N; i++)
            cin>>A[i];
        for(int i=0; i<M; i++)
            cin>>B[i];

        Solution ob;
        cout << ob.minInsAndDel(A,B,N,M) << endl;
    }
    return 0;
}
// } Driver Code Ends