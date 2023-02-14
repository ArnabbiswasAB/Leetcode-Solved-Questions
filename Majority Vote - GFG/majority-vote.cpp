//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
    vector<int> Solve(int n, vector<int>& nums) {
        // Code here
        
        vector<int>ans;
        int num1 = 0, num2 = 0, count1 = 0, count2 = 0;
        
        
        for(int i=0; i<n; i++){
            
            if(count1 == 0){
                count1 = 1;
                num1 = nums[i];
            }
            else if(count2 == 0){
                count2 = 1;
                num2 = nums[i];
            }
            else if(nums[i] == num1){
                count1++;
            }
            else if(nums[i] == num2){
                count2++;
            }else{
                count1--;
                count2--;
            }
            
        }
        
        
        count1 = 0, count2 = 0;
        for(int i=0; i<n; i++){
            
            if(nums[i] == num1)
            count1++;
            else if(nums[i] == num2)
            count2++;
        }
        
        
        if(count1 > (n/3))
        ans.push_back(num1);
        
        if(count2 > (n/3))
        ans.push_back(num2);
        
        
        if(ans.empty())
        return {-1};
        
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
        Solution obj;

        vector<int> res = obj.Solve(n, a);

        for (auto x : res) cout << x << " ";

        cout << "\n";
    }
    return 0;
}
// } Driver Code Ends