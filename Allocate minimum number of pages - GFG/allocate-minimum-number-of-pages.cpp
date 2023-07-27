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
    bool check(int A[], int N, int M, int mid){
        
        int sum = 0, count = 0;
        
        for(int i=0; i<N; i++){
            
            if(A[i] > mid)
            return false;
            
            sum += A[i];
            
            if(sum > mid){
                count++;
                sum = A[i];
            }
        }
        
        if(sum > 0)
        count++;
        
        return count<=M;
    }
    
    int findPages(int A[], int N, int M) 
    {
        
          if(N<M)
            return -1;
        
        int sum = 0, low = 0;
        for(int i=0; i<N; i++){
            low = min(low,A[i]);
            sum += A[i];
        }
        
        int high = sum, ans = -1;
        
        while(low<=high){
            
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