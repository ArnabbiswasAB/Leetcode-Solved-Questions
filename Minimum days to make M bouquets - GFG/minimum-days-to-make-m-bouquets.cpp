//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
  
  bool helper(vector<int>& bloom,int M,int K,int days){
       
       int count = 0, j = 0;
       
       for(int i=0; i<bloom.size(); i++){
           
           if(bloom[i] <= days){
               j++;
           }
           else{
               j = 0;
           }
           
           if(j == K)
           count++, j = 0;
       }
       
       return count >= M;
  }
  
  
    int solve(int M, int K, vector<int> &bloom){
      // Code here
      
      int n = bloom.size();
       int total = 1ll * M * K;

        if(total > n)
        return -1;
        
      int low = 1, high = *max_element(bloom.begin(),bloom.end());
      int ans = -1;
      
      while(low<=high){
          
          int mid = low + (high - low)/2;
          
          if(helper(bloom,M,K,mid)){
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
        int m, k;
    cin >> m >> k;
    string s;
    getline(cin, s);
    getline(cin, s);
    int n = s.length();
    int num = 0;
    bool f = 0;
    vector<int> bloomDay;
    for (int i = 0; i < n; i++)
    {
      if (s[i] == ' ')
      {
        if (!f)
          continue;
        bloomDay.push_back(num);
        num = 0;
        f = 0;
      }
      else
      {
        num = (num * 10) + (s[i] - '0');
        f = 1;
      }
    }
    if (f)
    {
      bloomDay.push_back(num);
    }
    Solution obj;
    cout<<obj.solve(m, k, bloomDay)<<endl;
    }
    return 0;
}
// } Driver Code Ends