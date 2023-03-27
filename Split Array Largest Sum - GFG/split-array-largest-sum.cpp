//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
  
  bool check(int arr[], int N, long long mid, int K){
      
      long long sum = 0 , count = 0;
      
      for(int i=0; i<N; i++){
          
          if(arr[i] > mid)
          return false;
          
          sum += arr[i];
          if(sum > mid){
              sum = arr[i];
              count++;
          }
          else if(sum == mid){
              sum = 0;
              count++;
          }
      }
      
      if(sum > 0)
      count++;
      
      return count <= K;
  }
  
  
    int splitArray(int arr[] ,int N, int K) {
        // code here
        
        long long low = LONG_MAX, high = 0;
        for(int i=0; i<N; i++){
            if(low > arr[i])
            low = arr[i];
            
            high += arr[i];
        }
        
        int ans = 0;
        
        while(low <= high){
            
            long long mid = low + (high - low)/2;
            
            if(check(arr,N,mid,K)){
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
    cin >> t;
    while (t--) {
        int N, K;
        
        cin>>N>>K;
        int arr[N];
        
        for(int i=0 ; i<N ; i++)
            cin>>arr[i];

        Solution ob;
        cout<<ob.splitArray(arr,N,K);
        cout<<"\n";
    }
    return 0;
}
// } Driver Code Ends