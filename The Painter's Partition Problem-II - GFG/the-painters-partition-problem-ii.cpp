//{ Driver Code Starts
// driver code

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function template for C++

class Solution
{
  public:
  bool check(int arr[], int n, int k, long long mid){
      
      long long sum = 0;
      long long count = 0;
      
      for(int i=0; i<n; i++){
      
            if(arr[i] > mid)
          return false;
          
           if(arr[i] + sum > mid){
             count++;
             sum = arr[i];
         }else{
             sum += arr[i];
         }
      }
      
      if(count<k)
     return true;
     
     return false;
  }
  
    long long minTime(int arr[], int n, int k)
    {
        // code here
        // return minimum time
        
        long long low = 0, high = 1e6, ans = 0;
        
        while(low <= high){
            long long mid = low + (high - low)/2;
            
            if(check(arr,n, k, mid)){
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

int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		int k,n;
		cin>>k>>n;
		
		int arr[n];
		for(int i=0;i<n;i++)
		    cin>>arr[i];
		Solution obj;
		cout << obj.minTime(arr, n, k) << endl;
	}
	return 0;
}
// } Driver Code Ends