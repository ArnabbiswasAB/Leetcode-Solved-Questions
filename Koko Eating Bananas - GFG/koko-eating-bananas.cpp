//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
  
  bool check(vector<int>& piles,int mid, int H){
      
      int hours = 0;
      
      for(int pile : piles){
          
          int divi = pile/mid;
          hours += divi;
          if(pile % mid != 0)
          hours++;
      }
      
      return hours<=H;
  }
  
  
    int Solve(int N, vector<int>& piles, int H) {
        // Code here
        
         int low = 1;
        int high = 1000000000;
        int ans = 0;
        
        while(low <= high){
              int mid = low + (high - low)/2;
             
             if(check(piles,mid,H)){
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
        int n;
        cin >> n;
        vector<int> a;
        for (int i = 0; i < n; ++i) {
            int x;
            cin >> x;
            a.push_back(x);
        }
        int h;
        cin >> h;
        Solution obj;

        cout << obj.Solve(n, a, h);
        cout << "\n";
    }
    return 0;
}
// } Driver Code Ends