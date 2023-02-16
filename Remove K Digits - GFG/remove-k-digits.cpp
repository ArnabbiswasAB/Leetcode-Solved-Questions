//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
    string removeKdigits(string nums, int k) {
        
        stack<char>st;
        
        if(nums.length() == k)
        return "0";
        
       
        string ans = "";
        
        for(int i=0; i<nums.length(); i++){
            
            while(!st.empty() && k>0 && st.top() > nums[i]){
            st.pop();
            k--;
            }
            
            if(st.empty() && nums[i] == '0')
            continue;
            
            st.push(nums[i]);
        }
        
        while(!st.empty() && k>0)
        {
            st.pop();
            k--;
        }
        
        if(st.empty())
        return "0";
        
        while(!st.empty()){
            ans += st.top();
            st.pop();
        }
        
        
        reverse(ans.begin(),ans.end());
        return ans;
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        string S;
        cin >> S;
        int K;
        cin >> K;
        Solution obj;
        cout << obj.removeKdigits(S, K) << endl;
    }
    return 0;
}

// } Driver Code Ends