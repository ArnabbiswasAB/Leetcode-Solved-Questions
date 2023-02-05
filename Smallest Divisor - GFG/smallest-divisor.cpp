//{ Driver Code Starts
// Initial Template for C++
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
  
  bool helper(vector<int>& nums, int K, int d){
      
      int count = 0;
      
      for(int i=0; i<nums.size(); i++){
          
          int divi = nums[i]/d;
          count += divi;
          if(nums[i] %  d != 0)
          count++;
      }
      
      return count <= K;
  }
  
  
    int smallestDivisor(vector<int>& nums, int K) {

        // Write your code here.
        int ans = 0, low = 1, high = *max_element(nums.begin(),nums.end());
        
        
        while(low <= high){
            
            int mid = low + (high - low)/2;
            
            if(helper(nums,K,mid)){
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
    int t = 1;
    cin >> t;

    // freopen ("output_gfg.txt", "w", stdout);

    while (t--) {
        // Input
        int n, k;
        cin >> n >> k;
        vector<int> vec(n);
        for (int i = 0; i < n; i++) cin >> vec[i];

        Solution obj;
        cout << obj.smallestDivisor(vec, k) << endl;
        // cout << "~\n";
    }
    // fclose(stdout);

    return 0;
}
// } Driver Code Ends