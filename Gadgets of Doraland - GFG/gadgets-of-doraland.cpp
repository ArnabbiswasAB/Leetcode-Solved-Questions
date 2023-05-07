//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution{
    public:
    
    static bool comp(pair<int,int>& a, pair<int,int>& b){
        
        if(a.second == b.second)
          return a.first > b.first;
          
        return a.second > b.second;  
    } 
    
    
    vector<int> TopK(vector<int>& arr, int k)
    {
        
        vector<int>ans;
        unordered_map<int,int>mp;
        vector<pair<int,int>> v;
        
        for(int i=0; i<arr.size(); i++)
           mp[arr[i]]++;
           
        for(auto it : mp){
           v.push_back({it.first,it.second});
        }   
        
        sort(v.begin(),v.end(), comp);
        
        for(int i=0; i<k; i++){
            ans.push_back(v[i].first);
        }
        
        return ans;
    }
};

//{ Driver Code Starts.

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n,k ;
        cin>>n;
        
        vector<int>array(n);
        
        for(int i=0; i<n; i++)
            cin>>array[i];
            
        cin>>k;
        
        Solution obj;
        vector<int> result = obj.TopK(array,k);
        
        for(int i=0; i<result.size();i++)
            cout<<result[i]<<" ";

        cout<<"\n";

    }
    return 0;
}
// } Driver Code Ends