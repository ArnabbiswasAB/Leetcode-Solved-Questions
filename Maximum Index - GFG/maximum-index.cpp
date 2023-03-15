//{ Driver Code Starts
#include <bits/stdc++.h>

using namespace std;

// } Driver Code Ends
class Solution{
public:
    int maxIndexDiff(int arr[], int N) {
        // code here
        
        int left[N], right[N];
        
        left[0] = arr[0], right[N-1] = arr[N-1];
        
        for(int i=1; i<N; i++)
           left[i] = min(arr[i], left[i-1]);
           
        for(int i = N-2; i>=0; i--)
           right[i] = max(arr[i] , right[i+1]);
           
        int i=0, j=0, ans= 0;
        
        while(i<N && j<N){
         
          if(left[i] <= right[j]){
              ans = max(ans, j - i);
              j++;
          }   
          else 
          i++;
        }
        
     return ans;   
    }
    
    /*
     int left[N];

       int right[N];

       left[0]=A[0];

       for(int i=1;i<N;i++)

       {

           left[i]=min(A[i],left[i-1]);

       }

       right[N-1]=A[N-1];

       for(int i=N-2;i>=0;i--)

       {

           right[i]=max(A[i],right[i+1]);

       }

      int ans=0,i=0,j=0;

       while(i<N && j<N)

       {

           if(left[i]<=right[j])

           {

               ans=max(ans,j-i);

               j++;

           }

           else

           i++;

       }

       return ans;
    */
};


//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, i;
        cin >> n;
        int a[n];
        for (i = 0; i < n; i++) {
            cin >> a[i];
        }
        Solution ob;
        auto ans = ob.maxIndexDiff(a, n);
        cout << ans << "\n";
    }
    return 0;
}
// } Driver Code Ends