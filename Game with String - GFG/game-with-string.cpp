//{ Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function Template for C++

class Solution{
public:
    int minValue(string s, int k){
        // code here
        
        unordered_map<int,int>mp;
        for(int i=0; i<s.length(); i++)
          mp[s[i]]++;
          
        priority_queue<int>pq;
        for(auto it : mp)
          pq.push(it.second);
          
        while(k--){
            int top = pq.top();
            pq.pop();
            
            top--;
            
            if(top>0)
            pq.push(top);
        }  
        
        int sum = 0;
        while(!pq.empty()){
            int top = pq.top();
            pq.pop();
            
            sum += (top*top);
        }
        
        return sum;
    }
};

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        string s;
        int k;
        cin>>s>>k;
        
        Solution ob;
        cout<<ob.minValue(s, k)<<"\n";
    }
    return 0;
}
// } Driver Code Ends