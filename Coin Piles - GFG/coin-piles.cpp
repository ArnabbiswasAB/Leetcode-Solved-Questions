//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++

class Solution {
  public:
  /*
  1.If you could limit the numbers within a certain max and min , such that max-min is k , you can be sure k is the max diff btw any pair .Hence sorting is obvious .
2.Now after a little brain storming one may conclude that every arr[i] can be treated as the min , and its corresponding max is arr[i]+k ,check point 1.

Under this assumption ,we have three regions ,
unsafe1 [0,i-1]
safe[i,point where element is arr[i]+k]
unsafe2 [point where element is arr[i]+k,n]

we are interested in reserving the safe and eliminating the unsafe r.
3.What's the best way to eliminate unsafe region ?
  delete all ? won't give optimal ans ,right?
  hence we replace all elements in that region unsafe 2 with arr[i]+k , 
  the difference is what we need to remove .
  
  and about the elements in region unsafe1 , those are of no use ,since 
  safe region has atmost diff of k , so obviously if you push min to 
  even more minimum , the gets diff>k .So simply eliminate these     elements.
  */
    int minSteps(int A[], int N, int K) {
      
      sort(A,A+N);
        int ans=INT_MAX,pre[N]={0};
        pre[0]=A[0];
        for(int i=1;i<N;i++) pre[i]=A[i]+pre[i-1];
        
        for(int i=0;i<N;i++){
            int probIndex = upper_bound(A,A+N,A[i]+K)-A;
            int pilesRemovedSum = i>0 ? pre[i-1] : 0;
            ans=min(ans, pilesRemovedSum + (pre[N-1]-pre[probIndex-1])-(N-probIndex)*(A[i]+K));
        }
        return ans;
    }
};


//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int N, K;
        cin>>N>>K;
        
        int A[N];
        for(int i=0; i<N; i++)
            cin>>A[i];

        Solution ob;
        cout << ob.minSteps(A,N,K) << endl;
    }
    return 0;
}
// } Driver Code Ends