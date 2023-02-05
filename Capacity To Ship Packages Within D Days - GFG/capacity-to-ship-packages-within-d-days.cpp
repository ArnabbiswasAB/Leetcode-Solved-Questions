//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++

class Solution {
  public:
  
  bool helper(int arr[], int N, int D, int wt){
      
      int count = 0, sum = 0;
      
      for(int i=0; i<N; i++){
          
          if(arr[i] > wt)
          return false;
          
          sum += arr[i];
          
          
          if(sum > wt){
              sum = arr[i];
              count++;
          }
      }
      
      count++;
      
      return count<=D;
  }
  
  
    int leastWeightCapacity(int arr[], int N, int D) {
        // code here
        
        int low = 1, high = 1e9, ans = 0;
        
        while(low <= high){
            
            int mid = low + ( high - low)/2;
            
            if(helper(arr, N, D, mid)){
                ans = mid;
                high = mid - 1;
            }
            else{
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
        int N,D;
        cin>>N;
        
        int arr[N];
        for(int i=0; i<N; i++)
            cin>>arr[i];
        cin>>D;

        Solution ob;
        cout << ob.leastWeightCapacity(arr,N,D) << endl;
    }
    return 0;
}
// } Driver Code Ends