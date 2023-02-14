//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
#include <iostream>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
    
    int merge(vector<int>& nums, int low, int mid, int high){
        
        int total = 0, j = mid + 1;
        for(int i = low; i<=mid; i++){
            while(j<=high && nums[i] > 2LL * nums[j])
              j++;
        
        
        total += (j - (mid + 1));
        }
        
        vector<int>ans;
        int left = low, right = mid + 1;
        
        while(left <= mid && right <= high){
            if(nums[left] <= nums[right])
            ans.push_back(nums[left++]);
            else
            ans.push_back(nums[right++]);
        }
        
        while(left<=mid){
            ans.push_back(nums[left++]);
        }
        
        while(right<=high){
            ans.push_back(nums[right++]);
        }
            
        for(int i=low; i<=high; i++){
            nums[i] = ans[i - low];
        }        
        
        return total;
    }
    
    
  int mergeSort(vector<int>& arr, int low, int high){
      
      if(low >= high)
      return 0;
      
      int mid = low + (high - low)/2;
      int inv_count = mergeSort(arr, low, mid);
      inv_count += mergeSort(arr, mid + 1, high);
      
      inv_count += merge(arr, low, mid, high);
      
      return inv_count;
  }
  
  
    int countRevPairs(int n, vector<int> arr) {
        // Code here
        
        return mergeSort(arr, 0, n-1);
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<int> arr;

        for (int i = 0; i < n; ++i) {
            int x;
            cin >> x;
            arr.push_back(x);
        }

        Solution obj;
        cout << obj.countRevPairs(n, arr) << endl;
    }
    return 0;
}
// } Driver Code Ends