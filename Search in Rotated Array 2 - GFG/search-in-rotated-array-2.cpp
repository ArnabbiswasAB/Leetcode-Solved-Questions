//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
    bool Search(int N, vector<int>& nums, int Key) {
        // Code here
        
        int low = 0, high = N-1;
        
        while(low <= high){
            
            int mid  = low + (high - low)/2;
            
            if(nums[mid] == Key)
            return true;
            
            if(nums[mid] == nums[low] && nums[mid] == nums[high]){
                low++;
                high--;
            }
            else if(nums[low] <= nums[mid]){
                
                if(Key>= nums[low] && Key<= nums[mid])
                high = mid - 1;
                else
                low = mid + 1;
            }
            else{
                
                if(Key>= nums[mid] && Key<= nums[high])
                low = mid + 1;
                else
                high = mid - 1;
            }
        }
        
        return false;
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<int> a;

        for (int i = 0; i < n; ++i) {
            int x;
            cin >> x;
            a.push_back(x);
        }
        int key;
        cin >> key;

        Solution obj;
        cout << obj.Search(n, a, key) << "\n";
    }
    return 0;
}
// } Driver Code Ends