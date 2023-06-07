//{ Driver Code Starts
#include <iostream>
#include <map>
#include <algorithm>
#include <cstdlib>
#include<bits/stdc++.h>

using namespace std;


// } Driver Code Ends
class Solution{
  public:
  
    static bool comp(pair<string,int>& a, pair<string,int>& b){
        
        if(a.second == b.second)
          return a.first < b.first;
          
        return a.second > b.second;  
    }
    
    //Function to return the name of candidate that received maximum votes.
    vector<string> winner(string arr[],int n)
    {
        // Your code here
        // Return the string containing the name and an integer
        // representing the number of votes the winning candidate got
   
        vector<string>ans;
        unordered_map<string,int>mp;
        
        for(int i=0; i<n; i++){
            mp[arr[i]]++;
        }
        
        vector<pair<string,int>> v;
        for(auto it : mp){
            v.push_back({it.first,it.second});
        }
        
        sort(v.begin(), v.end(), comp);
        
        ans.push_back(v[0].first);
        ans.push_back(to_string(v[0].second));
        
        return ans;
    }
};

//{ Driver Code Starts.

int main()
{
    int t;
    cin>>t;
    
    for(int i=0;i<t;i++)
    {
        
        
        int n;
        cin>>n;
        
        string arr[n];
        
        for (int i=0;i<n;i++)
        cin>>arr[i];
        Solution obj;
        vector<string> result = obj.winner(arr,n);
        
        cout<<result[0] << " " << result[1] << endl;
    }
    return 0;
}

// } Driver Code Ends