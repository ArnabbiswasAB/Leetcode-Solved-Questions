//{ Driver Code Starts
//Initial function template for C++

#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function template for C++

// arr : given vector of elements
// target : given sum value

class Solution{
  public:
    int threeSumClosest(vector<int> arr, int target) {
        // Your code goes here
        
        sort(arr.begin(),arr.end());
        
        int i=0,j=0,n=arr.size(), minDiff = INT_MAX, ans = 0;
        
        for(int i=0; i<n; i++){
            
            int j = i+1,k=n-1;
            
            while(j<k){
                int sum = arr[i] + arr[j] + arr[k];
                if(abs(sum - target) < minDiff){
                    minDiff = abs(sum - target);
                    ans = sum;
                }
                else if(abs(sum - target) == minDiff){
                    ans = max(ans,sum);
                }
                
                if(sum < target)
                  j++;
                  else
                  k--;
            }
        }
        
        return ans;
    }
};



//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while(t--) {
        
        int n,target;
        cin >> n >> target;
        
        vector<int> vec(n);
        
        for(int i = 0 ; i < n ; ++ i ) 
            cin >> vec[i];
        Solution obj;
        cout << obj.threeSumClosest(vec, target) << "\n";
    }
}

//Position this line where user code will be pasted.

// } Driver Code Ends