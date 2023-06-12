//{ Driver Code Starts
// Initial template for C++

#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function template in C++

class Solution 
{
    public:
    //Function to find minimum number of pages.
   bool check(int A[],int N,int students, int pages){
     
        int cnt = 0;
  int sumAllocated = 0;
  for (int i = 0; i < N; i++) {
    if (sumAllocated + A[i] > pages) {
      cnt++;
      sumAllocated = A[i];
      if (sumAllocated > pages) return false;
    } else {
      sumAllocated += A[i];
    }
  }
  if (cnt < students) return true;
  return false;
    }
    
    
    int findPages(int A[], int N, int M) 
    {
        //code here
        
        if(N<M)
        return -1;
        
        int low = 1, high = 0, ans = -1;
        for(int i=0; i<N; i++){
            high += A[i];
        }
        
        while(low <= high){
          
            int mid = low + (high - low)/2;
            
            if(check(A, N, M, mid)){
                ans = mid;
                high = mid - 1;
            }else{
                low = mid + 1;
            }
        } 
        
        return ans;
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        int A[n];
        for(int i=0;i<n;i++){
            cin>>A[i];
        }
        int m;
        cin>>m;
        Solution ob;
        cout << ob.findPages(A, n, m) << endl;
    }
    return 0;
}

// } Driver Code Ends